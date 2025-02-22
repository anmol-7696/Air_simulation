#include "Runway.h"

Runway::Runway(){
    onRunway = nullptr;
}

bool Runway::isAvailable(){
    return planeCount == 0;
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