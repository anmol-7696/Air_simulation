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
        void removeEvent();

};