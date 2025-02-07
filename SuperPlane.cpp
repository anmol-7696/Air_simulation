#include "SuperPlane.h"

SuperPlane::SuperPlane(string name, int flight, int atc, string type){
    this->setName(name);
    this->setFlight(flight);
    this->setAtc(atc);
    this->setType(type);
    this->setTurbulence(3);
}