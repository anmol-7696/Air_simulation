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
         // dummy method to make class abstract 
         virtual void dummyMethod() = 0; 
        
         // constructors 
         Event();
         Event(Plane*);
         
         // setters 
         void setTime(int);
         void setPlane(Plane*);
         void setCount(int);

         // getters 
         int getTime();
         int getCount();
         virtual Plane* getPlane();

         // virtual methods for overriding in requestTakeoff and requestLanding classes
         virtual void land();
         virtual void takeOff();

         // virtual methods for overriding in completeTakeoff and completeLandig classes
         virtual void finalLanding();
         virtual void finalTakeoff();

         virtual ~Event();         // destructor for the event class 
};  