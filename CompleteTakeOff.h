#pragma once 

#include "Event.h"
#include "Runway.h"

class CompleteTakeOff : public Event
{   
    private:
        int time;
        string num;
        Plane* p;
        Runway* r;
        int atc;
        string type;

    public:
          CompleteTakeOff();
          CompleteTakeOff(int, Plane*, string, int, string, Runway*);
          void dummyMethod() override;

         // void land() override;    
          //void takeOff() override; 

          void finalTakeoff() override;

          //void print();

          ~CompleteTakeOff() override;
};