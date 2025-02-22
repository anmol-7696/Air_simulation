// CLASS: LinkedList
//
// Author: Anmolpreet Singh, 7983556
//
// REMARKS: LinkedList to store events of planes landing and takeoff
//
//-------------------------------------------------------------------------

#include "LinkedList.h"
#include "Event.h"

#include "iostream"

using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
}

//-------------------------------------------------------------------------------
// add()
//
// PURPOSE: adds event to the end of the linkedlist 
// PARAMETERS: Event pointer 
// Returns: void 
//--------------------------------------------------------------------------------

void LinkedList::add(Event *e)
{
    Node *newNode = new Node(e, nullptr);

    if (head == nullptr)
    {
        head = newNode;
    }

    Node *curr = head;
    while (curr->getNext() != nullptr)
    {
        curr = curr->getNext();
    }
    curr->setNext(newNode);
}

//-------------------------------------------------------------------------------
// orderedInsert()
//
// PURPOSE: adds the event pointer in ordered insertion 
// PARAMETERS: Event pointer 
// Returns: void 
//--------------------------------------------------------------------------------

void LinkedList::orderedInsert(Event *e)
{
    Node *newNode = new Node(e, nullptr);

    // Case 1: Empty list OR inserting at the head (smallest time)
    if (head == nullptr || head->getEvent()->getTime() >= e->getTime())
    {
        newNode->setNext(head);
        head = newNode;

        return;
    }

    Node *curr = head;
    while (curr->getNext() != nullptr &&
           (curr->getNext()->getEvent()->getTime() <= e->getTime() ||
            (curr->getNext()->getEvent()->getTime() == e->getTime() &&
             curr->getNext()->getEvent()->getPlane()->getAtc() <= e->getPlane()->getAtc())))
    {
        curr = curr->getNext(); // Move forward
    }

    if (curr->getEvent() == e)
    {
        cout << "Warning: Duplicate event detected, skipping insertion." << endl;
        return; // Prevent re-inserting the same event
    }

    // Insert new node after `curr`
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);

    // cout <<"event added in middle" <<endl;
}

//-------------------------------------------------------------------------------
// isEmpty()
//
// PURPOSE: returns head == nullptr 
// PARAMETERS: none
// Returns: boolean operator 
//--------------------------------------------------------------------------------

bool LinkedList::isEmpty()
{
    return head == nullptr;
}

Node *LinkedList::getHead()
{
    return head;
}

//-------------------------------------------------------------------------------
// deleteHead()
//
// PURPOSE: removes the head from the linkedlist 
// PARAMETERS: none
// Returns: void 
//--------------------------------------------------------------------------------
void LinkedList::deleteHead()
{
    if (head == nullptr)
    {
        return;
    }

    Node *prev = head;
    head = head->getNext();
    delete prev;
}

// destructor 
LinkedList::~LinkedList()
{
    delete head;
}
