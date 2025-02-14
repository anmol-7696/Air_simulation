#include "CompleteTakeOff.h"
#include "iostream"

CompleteTakeOff::CompleteTakeOff(int time, Plane* p, string num, int atc, string type
                                  , Runway* runway)
{   
    this->time = time;
    this->p = p;
    this->num = num;
    this->atc = atc;
    this->type = type;
    this->r = runway;
}

int CompleteTakeOff::timeReq() {
    return time;
}

void CompleteTakeOff::land() {
    // ✅ Implement landing logic (even if empty)
}

void CompleteTakeOff::takeOff() {
    // ✅ Implement takeoff logic (even if empty)
}

void CompleteTakeOff::finalTakeoff(){
    std::cout << "TIME: " + to_string(time) + " -> " + p->getName() + " " + 
      p->getFlight() + " " + "(" + to_string(p->getAtc()) + ") " +
      p->getType() + " has cleared the runway" + to_string(p->getRunway()->getName()) << endl;
}