// CLASS: CompleteTakeOff
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: for completion of taking off events 
     //
//-------------------------------------------------------------------------

#pragma once 

#include "Event.h"
#include "Runway.h"

class CompleteTakeOff : public Event
{   
    private:
        int time;    // time for the event to be scheduled 
        string num;  // flight number for the event 
        Plane* p;    // plane associated with the event 
        Runway* r;   // runway assigned to the plane 
        int atc;     // atc Id for plane in the event 
        string type; // type of the plane  

    public:
          CompleteTakeOff();
          CompleteTakeOff(int, Plane*, string, int, string, Runway*);
          void dummyMethod() override;
          void finalTakeoff() override;
          Plane* getPlane() override;
          ~CompleteTakeOff() override;
};