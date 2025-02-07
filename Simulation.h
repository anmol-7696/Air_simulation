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
        void createEvent();
        void processEvent();
        void completeEvent();
        void readLine(string);

        //getters
        LinkedList* getPriorityQ();
        LinkedList* getWaitingLine();

};
