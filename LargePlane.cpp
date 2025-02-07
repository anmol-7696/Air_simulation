#include "LargePlane.h"

LargePlane::LargePlane(string name, int num, int atc, string type)
{
    this->setName(name);
    this->setFlight(num);
    this->setAtc(atc);
    this->setType(type);
    this->setTurbulence(1);
}