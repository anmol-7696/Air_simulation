#include "Plane.h"
#include "string"

using namespace std;

Plane::Plane() {}

Plane::Plane(const Plane& source) : name(source.name) , flightNum(source.flightNum) , atcId(source.atcId){}

Plane::~Plane(){}

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

string Plane::getName() const
{
    return name;
}

string Plane::getFlight() const
{
    return flightNum;
}
int Plane::getAtc() const
{
    return atcId;
}
string Plane::getType() const
{
    return type;
}
int Plane::getTurbulence() const
{
    return turbulence;
}
void Plane::setRunway(Runway* r){
    assignedRunway = r;
}
Runway* Plane::getRunway()const{
    return assignedRunway;
}
void Plane::removeRunway(){
    assignedRunway = new Runway();
}