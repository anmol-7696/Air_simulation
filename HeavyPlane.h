// CLASS: HeavyPlane
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: subclass for creating heavy plane 
     //
//-------------------------------------------------------------------------

#pragma once 

#include "Plane.h"
#include "string"

class HeavyPlane : public Plane
{
    private: 
          string type;
    public:
           HeavyPlane(string,string,int,string);
};