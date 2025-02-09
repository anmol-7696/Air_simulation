#include "RequestLanding.h"
#include <iostream>

using namespace std;

RequestLanding::RequestLanding(int time, Plane *p){
      this->setPlane(p);
      this->setTime(time);
      cout << "TIME: " + to_string(time) + " -> " + p->getName() + " " + 
      p->getFlight() + " " + "(" + to_string(p->getAtc()) + ") " +
      p->getType() + " ready for takeoff" << endl;
}

int RequestLanding::timeReq(){
    return 0;
}