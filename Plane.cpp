#include "Plane.h"
#include "string"

using namespace std;

Plane::Plane(){}

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

void Plane::setFlight(int num)
{
    this->flightNum = num;
}

void Plane::setAtc(int id)
{
    this->atcId = id;
}

void Plane::setType(string type)
{
    this->type = type;
}