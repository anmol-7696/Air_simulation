#pragma once 

// we can make this class as abstract 
class Event 
{
    public:
         virtual void process() = 0;
};