#pragma once 
#include "Event.h"
#include "Node.h"

class LinkedList
{   
    private:
        Node* head;
    public:
        LinkedList();
        void orderedInsert(Event*);
        bool isEmpty();
        Node* getHead();
        void deleteHead();
        void printQueue();
        void deleteEvent(int);

        // destructor
        virtual ~LinkedList();
};