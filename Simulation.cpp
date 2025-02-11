#include "Simulation.h"
#include "Plane.h"
#include "SmallPlane.h"
#include "HeavyPlane.h"
#include "SuperPlane.h"
#include "LargePlane.h"
#include "RequestTakeoff.h"
#include "RequestLanding.h"
#include "Runway.h"
#include "Event.h"
#include "CompleteTakeOff.h"
#include "CompleteLanding.h"
#include <vector>

Simulation::Simulation()
{
    this->priorityQueue = new LinkedList;
    this->waitingLine = new LinkedList;
}

Event *Simulation::createEvent(int time, string name, string flightNum, string type, string request,
                               int atc)
{
    Plane *p = nullptr;

    if (type == "small")
    {
        p = new SmallPlane(name, flightNum, atc, type);
    }
    else if (type == "large")
    {
        p = new LargePlane(name, flightNum, atc, type);
    }
    else if (type == "heavy")
    {
        p = new HeavyPlane(name, flightNum, atc, type);
    }
    else if (type == "super")
    {
        p = new SuperPlane(name, flightNum, atc, type);
    }

    if (p == nullptr)
    {
        return nullptr;
    }

    if (request == "takeoff")
    {
        return new RequestTakeoff(time, p);
    }
    else
    {
        return new RequestLanding(time, p);
    }
}

void Simulation::scheduleEvent(Event *e, vector<Runway> &runways)
{
    Runway *available = getAvailableRunway(runways);
    if (available)
    {
        available->assignPlane(e->getPlane());
        e->getPlane()->setRunway(available);
        this->getPriorityQ()->orderedInsert(e);

        waitingToPriority(runways);
    }
    else
    {
        this->getWaitingLine()->orderedInsert(e);
    }
}

void Simulation::processEvent()
{

    Event *e = this->getPriorityQ()->getHead()->getEvent();
    Event *event = nullptr;

    if (dynamic_cast<RequestTakeoff *>(e))
    {
        e->takeOff();
        event = new CompleteTakeOff(e->getTime() + 1 + e->getPlane()->getTurbulence(),
                                    e->getPlane(),
                                    e->getPlane()->getFlight(),
                                    e->getPlane()->getAtc(),
                                    e->getPlane()->getType(),
                                    e->getPlane()->getRunway());

        this->getPriorityQ()->orderedInsert(event);
        this->getPriorityQ()->deleteHead();
    }

    else if (dynamic_cast<RequestLanding *>(e))
    {
        e->land();
        event = new CompleteLanding(e->getTime() + 3 + e->getPlane()->getTurbulence(),
                                    e->getPlane(),
                                    e->getPlane()->getFlight(),
                                    e->getPlane()->getAtc(),
                                    e->getPlane()->getType(),
                                    e->getPlane()->getRunway());
        this->getPriorityQ()->orderedInsert(event);
        this->getPriorityQ()->deleteHead();
    }
}

Runway *Simulation::getAvailableRunway(vector<Runway> &runways)
{
    for (int i = 0; i < runways.size(); i++)
    {
        if (runways[i].isAvailable())
        {
            return &runways[i]; // Return the address of the available runway
        }
    }
    return nullptr; // No available runway
}

void Simulation::waitingToPriority(vector<Runway> &runways)
{
    // Check if there's an available runway
    Runway *available = getAvailableRunway(runways);
    if (available)
    {
        // If there is an available runway and waiting events
        if (!this->getWaitingLine()->isEmpty())
        {
            // Get the first event from the waiting line
            Event *waitingEvent = this->getWaitingLine()->getHead()->getEvent();
            this->getWaitingLine()->deleteHead();  // Remove it from waiting line

            // Assign runway to the plane in the event
            waitingEvent->getPlane()->setRunway(available);

            // Insert it into the priority queue
            this->getPriorityQ()->orderedInsert(waitingEvent);

            // Recurse to move more events if possible
            waitingToPriority(runways);
        }
    }
}


LinkedList* Simulation::getPriorityQ()
{
    return this->priorityQueue;
}

LinkedList* Simulation::getWaitingLine()
{
    return this->waitingLine;
}
