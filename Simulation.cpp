#include "Simulation.h"

Simulation::Simulation(){
    this->priorityQueue = new LinkedList;
    this->waitingLine = new LinkedList;
}

void Simulation::scheduleEvent(Event* e){
      this->getPriorityQ()->orderedInsert(e);
}


void Simulation::processEvent(){

}
void Simulation::completeEvent(){

        }
        


LinkedList* Simulation::getPriorityQ(){
    return this->priorityQueue;
}

LinkedList* Simulation::getWaitingLine(){
    return this->waitingLine;
}
