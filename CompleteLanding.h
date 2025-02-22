// CLASS: CompleteLanding
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: for completion of landing events
     //
//-------------------------------------------------------------------------

#pragma once
 
#include "Event.h"
#include "Runway.h"

class CompleteLanding : public Event
{   
    private:
        int time;    // time for the event to be scheduled 
        string num;  // flightNumber for the plane 
        Plane* p;    // Plane in the event 
        Runway* r;   // runway asssigned for the event 
        int atc;     // atc Id for the plane 
        string type; // type of the plane for event 

    public:
          CompleteLanding();  // null constructor 
          CompleteLanding(int, Plane*, string, int, string, Runway*); // parameter constructor 
          void dummyMethod() override; // dummy method overriden 
          void finalLanding()override; // finalLanding method to complete the event 
          Plane* getPlane() override;  // returns the plane associated with the event

          ~CompleteLanding() override; // destructor 
};