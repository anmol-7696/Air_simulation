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
        Event* createEvent(int, string, string, string, string,int);
        void scheduleEvent(Event*,vector<Runway>&);
        void processEvent();
        void completeEvent();
        void readLine(string);
        Runway* getAvailableRunway(vector<Runway>&);

        //getters
        LinkedList* getPriorityQ();
        LinkedList* getWaitingLine();

};
