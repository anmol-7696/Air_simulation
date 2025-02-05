#pragma once 

#include "string"

using namespace std;

class Plane 
{   
    private:
           string name;
           int flightNum;
           int atcId;
           string type;

    public:
           Plane();
           Plane(string, int, int);
           void setName(string);
           void setFlight(int);
           void setAtc(int);
           void setType(string);
};