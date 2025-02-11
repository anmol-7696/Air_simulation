#include "CompleteTakeOff.h"

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