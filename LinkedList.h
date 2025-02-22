// CLASS: LinkedList
     //
     // Author: Anmolpreet Singh, 7983556
     //
     // REMARKS: LinkedList to store events of planes landing and takeoff
     //
//-------------------------------------------------------------------------

#pragma once 

#include "Event.h"
#include "Node.h"

class LinkedList
{   
    private:
        Node* head;                 // variable for head node 
    public:
        LinkedList();
        void orderedInsert(Event*); // orderedInsert into the linkedlist
        bool isEmpty();             // checks if our linkedlist is empty 
        Node* getHead();            // returns head of the linkedlist 
        void deleteHead();          // deletes the head node 
        void add(Event*);           // adds into the linkedlist 

        // destructor
        virtual ~LinkedList();
};