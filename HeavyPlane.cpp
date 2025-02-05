#include "HeavyPlane.h"

HeavyPlane::HeavyPlane(string name, int num, int atc, string type)
{
    this->setName(name);
    this->setFlight(num);
    this->setAtc(atc);
    this->setType(type);
}