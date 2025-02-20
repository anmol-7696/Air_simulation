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