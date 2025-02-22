// CLASS: SuperPlane
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: SuperPlane subclass for Plane superclass 
     //
//-------------------------------------------------------------------------

#pragma once 

#include "Plane.h"
#include "string"

class SuperPlane : public Plane
{
    private: 
          string type;
    public:
           SuperPlane(string,string,int,string);
};