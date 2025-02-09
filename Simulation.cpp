#include "Simulation.h"
#include "Plane.h"
#include "SmallPlane.h"
#include "HeavyPlane.h"
#include "SuperPlane.h"
#include "LargePlane.h"
#include "RequestTakeoff.h"
#include "RequestLanding.h"
#include "Runway.h"
#include <vector>

Simulation::Simulation(){
    this->priorityQueue = new LinkedList;
    this->waitingLine = new LinkedList;
}

Event* Simulation::createEvent(int time, string name, string flightNum, string type, string request,
                               int atc){
    Plane* p = nullptr;

    if(type == "small"){
        Plane* p = new SmallPlane(name,flightNum,atc,type);
    }
    else if(type == "large"){
        Plane* p = new LargePlane(name,flightNum,atc,type);
    }
    else if(type == "heavy"){
        Plane* p = new HeavyPlane(name,flightNum,atc,type);
    }
    else if(type == "super"){
        Plane* p = new SuperPlane(name,flightNum,atc,type);
    }

    if(p == nullptr){
        return nullptr;
    }

    if(request == "takeoff"){
        return new RequestTakeoff(time,p);
    }
    else {
        return new RequestLanding(time,p);
    }

}

void Simulation::scheduleEvent(Event* e,vector<Runway>& runways){
      Runway* available = getAvailableRunway(runways);
      if(available){
        this->getPriorityQ()->orderedInsert(e);
      }
      else {
        this->getWaitingLine()->orderedInsert(e);
      }
}


void Simulation::processEvent(){

}
void Simulation::completeEvent(){

        }
        
Runway* Simulation::getAvailableRunway(vector<Runway>& runways){
   for (size_t i = 0; i < runways.size(); i++) {
        if (runways[i].isAvailable()) {
            return &runways[i];  // Return the address of the available runway
        }
    }
    return nullptr;  // No available runway
    
}

LinkedList* Simulation::getPriorityQ(){
    return this->priorityQueue;
}

LinkedList* Simulation::getWaitingLine(){
    return this->waitingLine;
}
