#pragma once 
#include "LinkedList.h"
#include "string"

using namespace std;

class Simulation 
{
    private:
        LinkedList* priorityQueue ;
        LinkedList* waitingLine;

    public:
        Simulation();
        void scheduleEvent(Event* event);
        void processEvent();
        void completeEvent();
        void readLine(string);

        //getters
        LinkedList* getPriorityQ();
        LinkedList* getWaitingLine();

};
