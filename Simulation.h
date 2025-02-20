#pragma once 

#include "LinkedList.h"
#include "string"

using namespace std;

class Simulation 
{
    private:
        LinkedList* priorityQueue ;
        LinkedList* waitingLine;
        int counter ;

    public:
        Simulation();
        Event* createEvent(int, string, string, string, string,int);
        void scheduleEvent(Event*,vector<Runway>&);
        void processEvent(vector<Runway>&);
        void completeEvent();
        void readLine(string);
        Runway* getAvailableRunway(vector<Runway>&);
        void waitingToPriority(vector<Runway>&);

        // set counter 

        //getters
        LinkedList* getPriorityQ();
        LinkedList* getWaitingLine();


        //destructor
        virtual ~Simulation();

};
