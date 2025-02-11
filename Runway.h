#pragma once 
#include "Plane.h"

class Runway
{   
    private:
        int name;
        Plane* onRunway;
    public:
        Runway();
        bool isAvailable();
        void assignPlane(Plane*);
        void removePlane();
        int getName();
};