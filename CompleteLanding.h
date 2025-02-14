#pragma once 
#include "Event.h"
#include "Runway.h"

class CompleteLanding : public Event
{   
    private:
        int time;
        string num;
        Plane* p;
        Runway* r;
        int atc;
        string type;

    public:
          CompleteLanding();
          CompleteLanding(int, Plane*, string, int, string, Runway*);
          int timeReq() override;

          void land() override;    
          void takeOff() override; 

          void finalLanding()override;
};