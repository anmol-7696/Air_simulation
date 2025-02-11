#include "Plane.h"
#include "string"

using namespace std;

Plane::Plane() {}

Plane::Plane(string name, int flight, int atc)
{
    this->name = name;
    this->flightNum = flight;
    this->atcId = atc;
}

void Plane::setName(string name)
{
    this->name = name;
}

void Plane::setFlight(string flight)
{
    this->flightNum = flight;
}

void Plane::setAtc(int id)
{
    this->atcId = id;
}

void Plane::setType(string type)
{
    this->type = type;
}

void Plane::setTurbulence(int turbulence)
{
    this->turbulence = turbulence;
}

string Plane::getName()
{
    return name;
}

string Plane::getFlight()
{
    return flightNum;
}
int Plane::getAtc()
{
    return atcId;
}
string Plane::getType()
{
    return type;
}
int Plane::getTurbulence()
{
    return turbulence;
}
void Plane::setRunway(Runway* r){
    assignedRunway = r;
}
Runway* Plane::getRunway(){
    return assignedRunway;
}
void Plane::removeRunway(){
    assignedRunway = new Runway();
}