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
    cout << available->getName() << endl;
    if (available)
    {   
        available->assignPlane(e->getPlane());
        e->getPlane()->setRunway(available);
        this->getPriorityQ()->orderedInsert(e); 
         waitingToPriority(runways);
    }
    else if(!available)
    {   
        this->getWaitingLine()->orderedInsert(e); // segmentation fault here (I am not creating event properly since no runway is avaialbe)
    }
}

void Simulation::processEvent()
{

    Event *e = this->getPriorityQ()->getHead()->getEvent();
    Event *event = nullptr;

    if (dynamic_cast<RequestTakeoff *>(e))
    {   
        int count = 0 ;
        while(count < 100){
            e->takeOff();
            cout <<"reached process event 1" << endl;
            event = new CompleteTakeOff(e->getTime() + 1 + e->getPlane()->getTurbulence(),
                                        e->getPlane(),
                                        e->getPlane()->getFlight(),
                                        e->getPlane()->getAtc(),
                                        e->getPlane()->getType(),
                                        e->getPlane()->getRunway());
            cout <<"reached process event 1" << endl;

            if(event == nullptr){
                cout <<"event is null" << endl;
                return;
            }
            if(this->getPriorityQ() == nullptr){
                cout <<"Q is null" << endl;
                return;
            }
            this->getPriorityQ()->orderedInsert(event); // segmentation fault 
            cout <<"reached process event 1" << endl;
            count++;
        }
    }

    else if (dynamic_cast<RequestLanding *>(e))
    {   
        cout <<"reached process event 2" << endl;
        e->land();
        event = new CompleteLanding(e->getTime() + 3 + e->getPlane()->getTurbulence(),
                                    e->getPlane(),
                                    e->getPlane()->getFlight(),
                                    e->getPlane()->getAtc(),
                                    e->getPlane()->getType(),
                                    e->getPlane()->getRunway());

        this->getPriorityQ()->orderedInsert(event);
    }
    this->getPriorityQ()->deleteHead();
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
    while (true)
    {
        Runway *available = getAvailableRunway(runways);
        if (!available)
        {
            cout << "Runway not available" << endl;
            return;
        }

        if (this->getWaitingLine()->isEmpty()) {
            return; // ✅ Stop when waiting line is empty
        }

        Event *waitingEvent = this->getWaitingLine()->getHead()->getEvent();
        this->getWaitingLine()->deleteHead(); 

        waitingEvent->getPlane()->setRunway(available);
        this->getPriorityQ()->orderedInsert(waitingEvent);
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
