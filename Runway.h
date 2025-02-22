// CLASS: Runway 
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: class for Runways 
     //
//-------------------------------------------------------------------------


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
        int getName();
        void setName(int);

       // destructor
        ~Runway();
};