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

#include <iostream>

using namespace std;

Simulation::Simulation()
{
    this->priorityQueue = new LinkedList();
    this->waitingLine = new LinkedList();
    this->timeWasted = 0;
}

//-------------------------------------------------------------------------------
// createEvent() 
//
// PURPOSE: creates an event
// PARAMETERS: time -> time when the event is scheduled for 
//             name -> name of the plane 
//             flightNum -> flight number 
//             type ->  plane type 
//             request -> type of request 
//             atc -> atc id for the plane 
// Returns: Event*
//--------------------------------------------------------------------------------
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
    if (request == "landing")
    {
        return new RequestLanding(time, p);
    }

    return nullptr;
}

//-------------------------------------------------------------------------------
// scheduleEvent() 
//
// PURPOSE: adds event into the priority queue or waiting line depending on the availablity of runways 
// PARAMETERS: e-> event pointer 
//             runways -> vector reference of runways
// Returns: void 
//--------------------------------------------------------------------------------
void Simulation::scheduleEvent(Event *e, vector<Runway> &runways)
{

    Runway *available = getAvailableRunway(runways);
    if (available)
    {
        available->assignPlane(e->getPlane());
        e->getPlane()->setRunway(available);
        this->getPriorityQ()->orderedInsert(e);
        waitingToPriority(runways);
        this->timeWasted++;
    }
    else
    {
        this->getWaitingLine()->orderedInsert(e); // Add event to waiting line
        this->timeWasted++;
    }
}

//-------------------------------------------------------------------------------
// processEvent() 
//
// PURPOSE: processes simulation for the given line of code (text file is processed one by one )
// PARAMETERS: runways reference 
// Returns: void 
//--------------------------------------------------------------------------------
void Simulation::processEvent(vector<Runway> &runways)
{   
  int i = 1;

  Event* e = nullptr;
  Event* event = nullptr;

 while (!(this->getPriorityQ()->isEmpty()))
  {    
        Node *headNode = this->getPriorityQ()->getHead();
        e = headNode->getEvent();

        if (dynamic_cast<CompleteTakeOff *>(e) != nullptr)
        {
            e->finalTakeoff();
            e->getPlane()->getRunway()->removePlane();
        }

        else if (dynamic_cast<CompleteLanding *>(e) != nullptr)
        {
            e->finalLanding();
            e->getPlane()->getRunway()->removePlane();
        }

        else if (dynamic_cast<RequestTakeoff *>(e) != nullptr)
        {   
            e->takeOff();
            int completionTime = e->getTime() + 1 + e->getPlane()->getTurbulence();

            event = new CompleteTakeOff(completionTime , e->getPlane(), e->getPlane()->getFlight(),
                                               e->getPlane()->getAtc(),
                                               e->getPlane()->getType(),
                                               e->getPlane()->getRunway());
            this->getPriorityQ()->add(event);
        }
        else if (dynamic_cast<RequestLanding *>(e) != nullptr)
        {
            e->land();
            int completionTime = e->getTime() + 3 + e->getPlane()->getTurbulence();
            event = new CompleteLanding(completionTime , e->getPlane(), e->getPlane()->getFlight(),
                                               e->getPlane()->getAtc(),
                                               e->getPlane()->getType(),
                                               e->getPlane()->getRunway());
            this->getPriorityQ()->add(event);
        }

         this->getPriorityQ()->deleteHead();
     }
}

//-------------------------------------------------------------------------------
// getAvailableRunway() 
//
// PURPOSE: available runway 
// PARAMETERS: runways reference 
// Returns: Runway*
//--------------------------------------------------------------------------------
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

//-------------------------------------------------------------------------------
// waitingToPriority() 
//
// PURPOSE: adds events in waiting line to priority queue 
// PARAMETERS: runways vector reference 
// Returns: void 
//--------------------------------------------------------------------------------
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

int Simulation::getTimeWasted(){
    return timeWasted;
}

// destructor for the simulation class 
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
