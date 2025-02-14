#include "Runway.h"
#include "Plane.h"


Runway::Runway(){
    onRunway = new Plane();
}

bool Runway::isAvailable(){
    return onRunway->getName() == "";
}

void Runway::assignPlane(Plane* p){
    onRunway = p;
}

void Runway::removePlane(){
    onRunway = new Plane();
}

int Runway::getName(){
    return name;
}

void Runway::setName(int name){
    this->name = name;
}