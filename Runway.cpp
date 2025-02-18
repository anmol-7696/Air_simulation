#include "Runway.h"
#include "Plane.h"


Runway::Runway(){
    onRunway = nullptr;
}

bool Runway::isAvailable(){
    return onRunway == nullptr;
}

void Runway::assignPlane(Plane* p){
    onRunway = p;
}

void Runway::removePlane(){
    onRunway = nullptr;
}

int Runway::getName(){
    return name;
}

void Runway::setName(int name){
    this->name = name;
}

Runway::~Runway(){
    
}