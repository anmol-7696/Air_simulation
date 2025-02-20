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
          void dummyMethod() override;
          void finalLanding()override;

          ~CompleteLanding() override;
};