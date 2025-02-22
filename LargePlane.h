// CLASS: LargePlane
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: subclass for creating Large Plane 
     //
//-------------------------------------------------------------------------

#pragma once 

#include "Plane.h"
#include "string"

class LargePlane : public Plane
{
    private: 
          string type;
    public:
           LargePlane(string,string,int,string);
};