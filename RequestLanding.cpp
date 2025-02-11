#include "RequestLanding.h"
#include <iostream>

using namespace std;

RequestLanding::RequestLanding(int time, Plane *p){
      this->setPlane(p);
      this->setTime(time);
      cout << "TIME: " + to_string(time) + " -> " + p->getName() + " " + 
      p->getFlight() + " " + "(" + to_string(p->getAtc()) + ") " +
      p->getType() + " inbound for landing" << endl;
}

int RequestLanding::timeReq(){
    return 0;
}

void RequestLanding::land(){
     cout << "TIME: " + to_string(this->getTime()) + " -> " + this->getPlane()->getName() + " " +
    this->getPlane()->getFlight() + " " + "(" + to_string(this->getPlane()->getAtc()) + ")" + 
    this->getPlane()->getType() + " cleared for landing on runway " + to_string(this->getPlane()->getRunway()->getName())
    + ". (time req. for landing: " + to_string(3 + this->getPlane()->getTurbulence()) + ")"; 
}