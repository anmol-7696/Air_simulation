#include "Runway.h"

Runway::Runway(){
    onRunway = Plane();
}

bool Runway::isAvailable(){
    return onRunway.getName() == "";
}

void Runway::assignPlane(Plane p){
    onRunway = p;
}

void Runway::removePlane(){
    onRunway = Plane();
}