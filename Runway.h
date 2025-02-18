#pragma once 

class Plane;

class Runway
{   
    private:
        int name;
        int planeCount;
        Plane* onRunway;
    public:
        Runway();
        bool isAvailable();
        void assignPlane(Plane*);
        void removePlane();
        // int getPlaneCount();
        // void setPlaneCount(int);
        int getName();
        void setName(int);

       // destructor
        ~Runway();
};