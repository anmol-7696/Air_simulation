#pragma once 
#include "Plane.h"

class Runway
{   
    private:
        Plane onRunway;
    public:
        Runway();
        bool isAvailable();
        void assignPlane(Plane);
        void removePlane();
};