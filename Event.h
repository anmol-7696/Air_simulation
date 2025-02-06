#pragma once 

// we can make this class as abstract 
class Event 
{   
    private:
         int time;
    public:
         virtual void process() = 0;
         int getTime();
};