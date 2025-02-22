// CLASS: Node 
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: Node class for storing events 
     //
//-------------------------------------------------------------------------


#pragma once

#include "Event.h"

class Node 
{
    private:
        Event* event;
        Node* next;

    public: 
        // constructor 
        Node(Event* , Node*);    

        //Instance methods
        Node* getNext();
        void setNext(Node*);
        void setEvent(Event*);
        Event* getEvent();
        virtual ~Node();
};