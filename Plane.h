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
           Plane(string, int, int, string, int, Runway*);
           void removeRunway();

           // copy constructor
           Plane(const Plane&);
           //destructor 
           ~Plane();
           
           //setters
           void setName(string);
           void setFlight(string);
           void setAtc(int);
           void setType(string);
           void setTurbulence(int);
           void setRunway(Runway*);


           //getters
           string getName() const;
           string getFlight() const;
           int getAtc() const;
           string getType() const;
           int getTurbulence() const;
           Runway* getRunway() const;
};