#include "RequestTakeoff.h"
#include <iostream>

using namespace std;

RequestTakeoff::RequestTakeoff(int time, Plane *p){
      this->setPlane(p);
      this->setTime(time);
      cout << "TIME: " + to_string(time) + " -> " + p->getName() + " " + 
      to_string(p->getFlight()) + " " + "(" + to_string(p->getAtc()) + ") " +
      p->getType() + " ready for takeoff" << endl;
}

int RequestTakeoff::timeReq(){
    return 0;
}
