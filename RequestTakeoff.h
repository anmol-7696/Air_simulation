#pragma once 
#include "Plane.h"
#include "string"
#include "Event.h"

class RequestTakeoff : public Event
{   
    public:
        RequestTakeoff(int,Plane*, int);
        int timeReq()override;
        void takeOff() override;
       // Plane* getPlane() override;
        virtual ~RequestTakeoff() ;
};