#include "Runway.h"

Runway::Runway(){
    onRunway = new Plane();
    name++;
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
