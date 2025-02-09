#pragma once 

#include "string"

using namespace std;

class Plane 
{   
    private:
           string name;
           string flightNum;
           int atcId;
           int turbulence;
           string type;

    public:
           Plane();
           Plane(string, int, int);
           
           //setters
           void setName(string);
           void setFlight(string);
           void setAtc(int);
           void setType(string);
           void setTurbulence(int);

           //getters
           string getName();
           string getFlight();
           int getAtc();
           string getType();
           int getTurbulence();
};