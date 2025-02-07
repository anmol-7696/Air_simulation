#pragma once 

#include "string"

using namespace std;

class Plane 
{   
    private:
           string name;
           int flightNum;
           int atcId;
           int turbulence;
           string type;

    public:
           Plane();
           Plane(string, int, int);
           
           //setters
           void setName(string);
           void setFlight(int);
           void setAtc(int);
           void setType(string);
           void setTurbulence(int);

           //getters
           string getName();
           int getFlight();
           int getAtc();
           string getType();
           int getTurbulence();
};