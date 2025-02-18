#pragma once 

class Plane;

class Runway
{   
    private:
        int name;
        Plane* onRunway;
    public:
        Runway();
        bool isAvailable();
        void assignPlane(Plane*);
        void removePlane();
        int getName();
        void setName(int);

       // destructor
        ~Runway();
};