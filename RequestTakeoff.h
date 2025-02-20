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