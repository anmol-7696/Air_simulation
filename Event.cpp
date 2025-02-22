#include "Event.h"

Event::Event(Plane* p) : plane(p) {}

Event::Event(){
    this->plane = nullptr;
}

void Event::setTime(int time){
    this->time = time;
}

int Event::getTime(){
     return time;
}

void Event::setPlane(Plane* p){
    this->plane = p;
}

Plane* Event::getPlane(){
    return plane;
}


void Event::finalLanding(){

}

void Event::finalTakeoff(){

}
void Event::land(){

}

void Event::takeOff(){
    
}

// destructor 
Event::~Event(){
    
}

