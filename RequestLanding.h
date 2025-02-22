// CLASS: RequestLanding 
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: creates an event when any plane requests landing 
     //
//-------------------------------------------------------------------------

#pragma once 

#include "Plane.h"
#include "string"
#include "Event.h"

class RequestLanding : public Event
{   
    public:
        RequestLanding(int,Plane*);
        void dummyMethod() override;
        void land() override;
         ~RequestLanding() override;
};