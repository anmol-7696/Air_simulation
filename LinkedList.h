#pragma once 
#include "Event.h"
#include "Node.h"

class LinkedList
{   
    private:
        Node* head;
        int siz;
    public:
        LinkedList();
        void orderedInsert(Event*);
        bool isEmpty();
        Node* getHead();
        void deleteHead();
        void printQueue();
        void deleteEvent(int);
        void add(Event*);
        int size();

        void setHead(Node*);
        // destructor
        virtual ~LinkedList();
};