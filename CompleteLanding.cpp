#include "CompleteLanding.h"
#include <iostream>

CompleteLanding::CompleteLanding(int time, Plane* p, string num, int atc, string type
                                  , Runway* runway)
{   
    this->time = time;
    this->p = p;
    this->num = num;
    this->atc = atc;
    this->type = type;
    this->r = runway;
   
}

void CompleteLanding::finalLanding(){
    std::cout << "TIME: " + to_string(time) + " -> " + p->getName() + " " + 
      p->getFlight() + " " + "(" + to_string(p->getAtc()) + ") " +
      p->getType() + " has cleared the runway " + to_string(p->getRunway()->getName()) + "\n" << endl;
}

int CompleteLanding::timeReq() {
    return time;
}

void CompleteLanding::land() {
}

void CompleteLanding::takeOff() {
    
}


CompleteLanding::~CompleteLanding(){

}