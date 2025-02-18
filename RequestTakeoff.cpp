#include "RequestTakeoff.h"
#include <iostream>

using namespace std;

RequestTakeoff::RequestTakeoff(int time, Plane *p) : Event(p){
      this->setPlane(p);
      this->setTime(time);
      cout << "TIME: " + to_string(time) + " -> " + p->getName() + " " + 
      p->getFlight() + " " + "(" + to_string(p->getAtc()) + ") " +
      p->getType() + " ready for takeoff\n" << endl;
}

int RequestTakeoff::timeReq(){
    return 0;
}

void RequestTakeoff::takeOff(){
    cout << "TIME: " + to_string(this->getTime()) + " -> " + this->getPlane()->getName() + " " +
    this->getPlane()->getFlight() + " " + "(" + to_string(this->getPlane()->getAtc()) + ") " + 
    this->getPlane()->getType() + " cleared for takeoff on runway " + to_string(this->getPlane()->getRunway()->getName())
    + ". (time req. for takeoff: " + to_string(1 + this->getPlane()->getTurbulence()) + ")\n" <<endl ; 
}


RequestTakeoff::~RequestTakeoff(){
    
}
