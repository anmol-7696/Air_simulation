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

#include <iostream>

using namespace std;

Simulation::Simulation()
{
    this->priorityQueue = new LinkedList();
    this->waitingLine = new LinkedList();
    counter = 1;
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
        return new RequestTakeoff(time, p, counter);
        counter++;
    }
    if (request == "landing")
    {
        return new RequestLanding(time, p, counter);
        counter++;
    }

    return nullptr;
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
        this->getWaitingLine()->add(e); // Add event to waiting line
    }
}

void Simulation::processEvent(vector<Runway> &runways)
{   
  int i = 1;

  Event* e = nullptr;
  Event* event = nullptr;

 while (!(this->getPriorityQ()->isEmpty()))
  {    
        Node *headNode = this->getPriorityQ()->getHead();
        e = headNode->getEvent();
        cout << "Queue size: " << this->getPriorityQ()->size() << endl;


        // cout << "reached here " + to_string(i) << endl;
        // std::cout << "Event type: " << typeid(*e).name() << std::endl;
        // cout << "reached here " + to_string(i) << endl;

        if (dynamic_cast<CompleteTakeOff *>(e))
        {
            e->finalTakeoff();
        }

        else if (dynamic_cast<CompleteLanding *>(e))
        {
            e->finalLanding();
        }

        else if (dynamic_cast<RequestTakeoff *>(e))
        {   
            e->takeOff();
            int completionTime = e->getTime() + 1 + e->getPlane()->getTurbulence();

            event = new CompleteTakeOff(completionTime, e->getPlane(), e->getPlane()->getFlight(),
                                               e->getPlane()->getAtc(),
                                               e->getPlane()->getType(),
                                               e->getPlane()->getRunway(), counter);
            counter++;
            this->getPriorityQ()->add(event);
        }
        else if (dynamic_cast<RequestLanding *>(e))
        {
            e->land();
            int completionTime = e->getTime() + 3 + e->getPlane()->getTurbulence();
            event = new CompleteLanding(completionTime, e->getPlane(), e->getPlane()->getFlight(),
                                               e->getPlane()->getAtc(),
                                               e->getPlane()->getType(),
                                               e->getPlane()->getRunway(), counter);
            counter++;
            this->getPriorityQ()->add(event);
        }

        this->getPriorityQ()->deleteHead();
     }
}


Runway *Simulation::getAvailableRunway(vector<Runway> &runways)
{
    for (int i = 0; i < runways.size(); i++)
    {
        if (runways[i].isAvailable())
        {
            return &runways[i];
        }
    }
    return nullptr;
}

void Simulation::waitingToPriority(vector<Runway> &runways)
{
    Runway *available = getAvailableRunway(runways);
    if (!available)
    {
        return;
    }

    if (this->getWaitingLine()->isEmpty())
    {
        return;
    }

    Event *waitingEvent = this->getWaitingLine()->getHead()->getEvent();
    this->getWaitingLine()->deleteHead();

    waitingEvent->getPlane()->setRunway(available);
    this->getPriorityQ()->orderedInsert(waitingEvent);
}

LinkedList *Simulation::getPriorityQ()
{
    return this->priorityQueue;
}

LinkedList *Simulation::getWaitingLine()
{
    return this->waitingLine;
}

Simulation::~Simulation()
{
    while (!priorityQueue->isEmpty())
    {
        Event *e = priorityQueue->getHead()->getEvent();
        priorityQueue->deleteHead();
        delete e;
    }
    delete priorityQueue;

    while (!waitingLine->isEmpty())
    {
        Event *e = waitingLine->getHead()->getEvent();
        waitingLine->deleteHead();
        delete e;
    }
    delete waitingLine;
 }
