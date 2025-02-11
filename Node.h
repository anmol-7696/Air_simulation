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
        Event* getEvent();
        void print();
        ~Node();
};