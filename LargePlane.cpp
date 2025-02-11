#include "LargePlane.h"

LargePlane::LargePlane(string name, string flight, int atc, string type){
    this->setName(name);
    this->setFlight(flight);
    this->setAtc(atc);
    this->setType(type);
    this->setTurbulence(1);
}