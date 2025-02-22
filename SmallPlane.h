// CLASS: SmallPlane
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: SmallPlane sublclass which creates smallPlane
     //
//-------------------------------------------------------------------------


#pragma once 

#include "Plane.h"
#include "string"

using namespace std;

class SmallPlane: public Plane
{   
    public:
          SmallPlane(string,string,int,string);
};