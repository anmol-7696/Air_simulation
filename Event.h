#pragma once 
#include "Plane.h"

// we can make this class as abstract 
class Event 
{   
    private:
         Plane* plane;
         int time;
    public:
         virtual int timeReq() = 0;
         int getTime();
         void setTime(int);
         void setPlane(Plane*);
         Plane* getPlane();
};