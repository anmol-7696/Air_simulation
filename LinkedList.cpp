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

void LinkedList::add(Event* e)
{   
    Node* newNode = new Node(e,nullptr);

    if(head == nullptr){
        head = newNode;
    }
   
    Node* curr = head;
    while(curr->getNext() != nullptr){
        curr = curr->getNext();
    }
    curr->setNext(newNode);
    siz++;
}

void LinkedList::orderedInsert(Event *e)
{

    Node *newNode = new Node(e, nullptr);
    if (newNode == nullptr)
    {
        return;
    }

    // Case 1: Empty list OR inserting at the head (smallest time)
    if (head == nullptr || head->getEvent()->getTime() > e->getTime())
    {
        newNode->setNext(head);
        head = newNode;
        siz++;
        return;
    }

    Node *curr = head;
    while (curr->getNext() != nullptr &&
           (curr->getNext()->getEvent()->getTime() < e->getTime() ||
            (curr->getNext()->getEvent()->getTime() == e->getTime() &&
             curr->getNext()->getEvent()->getPlane()->getAtc() < e->getPlane()->getAtc())))
    {
        curr = curr->getNext(); // Move forward
    }

    // Insert new node after `curr`
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
    siz++;
    //cout <<"event added in middle" <<endl;
}


bool LinkedList::isEmpty()
{   
    return head == nullptr;

}

Node *LinkedList::getHead()
{
    return head;
}

void LinkedList::deleteHead()
{
    if (head == nullptr)
    {
        return;
    }

    Node *prev = head;
    head = head->getNext();
    delete prev;
    siz--;
}

void LinkedList::setHead(Node* head){
    this->head = head;
}

int LinkedList::size(){
    return siz;
}

void LinkedList::printQueue() {
    Node* curr = head;
    while (curr != nullptr) {
        cout << "Event time: " << curr->getEvent()->getPlane()->getName() << endl;
        curr = curr->getNext();
    }
}


LinkedList::~LinkedList(){
   delete head;
}

