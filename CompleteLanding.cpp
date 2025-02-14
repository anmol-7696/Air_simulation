#include "CompleteLanding.h"

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

int CompleteLanding::timeReq() {
    return time;
}

void CompleteLanding::land() {
    // ✅ Implement landing logic (even if empty)
}

void CompleteLanding::takeOff() {
    // ✅ Implement takeoff logic (even if empty)
}