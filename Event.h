// CLASS: Event
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: event abstract class 
     //
//-------------------------------------------------------------------------

#pragma once 

#include "Plane.h"

class Event 
{   
    private:
         Plane* plane; // plane associated with the event 
         int time;     // time for the event to schedule 
    public:
         virtual void dummyMethod() = 0; // dummy method to make class abstract 
         Event(Plane*);
         Event();

         int getTime();
         void setTime(int);
         void setPlane(Plane*);
         void setCount(int);


         int getCount();
         virtual Plane* getPlane();
         virtual void land();
         virtual void takeOff();

         virtual void finalLanding();
         virtual void finalTakeoff();

         virtual ~Event();         // destructor for the event class 
};  