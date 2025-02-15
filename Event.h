#pragma once 
#include "Plane.h"

// we can make this class as abstract 
class Event 
{   
    private:
         Plane* plane;
         int time;
         int eventCount;
    public:
         virtual int timeReq() = 0;
         Event(Plane*);
         Event();

         int getTime();
         void setTime(int);
         void setPlane(Plane*);
         void setCount(int);


         int getCount();
         Plane* getPlane();
         virtual void land();
         virtual void takeOff();

         virtual void finalLanding();
         virtual void finalTakeoff();

         virtual ~Event();
};