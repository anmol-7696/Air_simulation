#include "Event.h"

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

void Event::land(){

}

void Event::takeOff(){
    
}

Event::~Event(){
    
}

