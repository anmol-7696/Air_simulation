// CLASS: RequestTakeOff
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: creates an event when any plane requests takeOff
     //
//-------------------------------------------------------------------------

#pragma once 

#include "Plane.h"
#include "string"
#include "Event.h"

class RequestTakeoff : public Event
{   
    public:
        RequestTakeoff(int,Plane*);
        void dummyMethod()override;
        void takeOff() override;
       // Plane* getPlane() override;
         ~RequestTakeoff() override;
};