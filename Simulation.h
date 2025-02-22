// CLASS: Simulation 
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: Simulation class which handles our event driven simulation 
     //
//-------------------------------------------------------------------------


#pragma once 

#include "LinkedList.h"
#include "string"

#include <vector>

using namespace std;

class Simulation 
{
    private:
        LinkedList* priorityQueue ; // linkedlist for priorityQueue
        LinkedList* waitingLine;    // linkedlist to accomodate waiting line  
        int timeWasted;             // counter for the time wasted while runways were not available 

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
        void setTimeWasted(int);

        //getters
        LinkedList* getPriorityQ();
        LinkedList* getWaitingLine();
        int getTimeWasted();


        //destructor
        virtual ~Simulation();

};
