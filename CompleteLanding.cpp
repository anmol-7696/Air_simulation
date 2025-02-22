#include "CompleteLanding.h"
#include <iostream>


//-------------------------------------------------------------------------------
// CompleteLanding constructor
//--------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------
// getPlane() 
//
// PURPOSE: returns the plane associated with the event 
// PARAMETERS: none
// Returns: Plane*
//--------------------------------------------------------------------------------

Plane* CompleteLanding::getPlane(){
    return p;
}

void CompleteLanding::finalLanding(){
    std::cout << "TIME: " + to_string(time) + " -> " + p->getName() + " " + 
      p->getFlight() + " " + "(" + to_string(p->getAtc()) + ") " +
      p->getType() + " has cleared the runway " + to_string(p->getRunway()->getName()) + "\n" << endl;
}

void CompleteLanding::dummyMethod() {
    
}

// destructor 
CompleteLanding::~CompleteLanding(){

}