#pragma once 
#include "Plane.h"
#include "string"
#include "Event.h"

class RequestLanding : public Event
{   
    public:
        RequestLanding(int,Plane*, int);
        int timeReq()override;
        void land() override;
         ~RequestLanding() override;
};