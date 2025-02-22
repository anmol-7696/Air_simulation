#include "CompleteTakeOff.h"
#include "iostream"
#include "string"

using namespace std;

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

void CompleteTakeOff::dummyMethod() {
    
}

Plane* CompleteTakeOff::getPlane(){
    return p;
}

void CompleteTakeOff::finalTakeoff(){
    std::cout << "TIME: " + to_string(time) + " -> " + p->getName() + " " + 
      p->getFlight() + " " + "(" + to_string(p->getAtc()) + ") " +
      p->getType() + " has cleared the runway " + to_string(p->getRunway()->getName()) + "\n" << endl;
}

// destructor 
CompleteTakeOff::~CompleteTakeOff(){
    
}