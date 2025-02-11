#pragma once 

#include "string"
#include "Runway.h"

using namespace std;

class Plane 
{   
    private:
           string name;
           string flightNum;
           int atcId;
           int turbulence;
           string type;
           Runway* assignedRunway;

    public:
           Plane();
           Plane(string, int, int);
           void removeRunway();
           
           //setters
           void setName(string);
           void setFlight(string);
           void setAtc(int);
           void setType(string);
           void setTurbulence(int);
           void setRunway(Runway*);


           //getters
           string getName();
           string getFlight();
           int getAtc();
           string getType();
           int getTurbulence();
           Runway* getRunway();
};