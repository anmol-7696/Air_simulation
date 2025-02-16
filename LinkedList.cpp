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

}

void LinkedList::orderedInsert(Event *e)
{

    Node *newNode = new Node(e, nullptr);
    if (newNode == nullptr)
    {
        // Handle memory allocation failure
        return;
    }

    // Case 1: Empty list OR inserting at the head (smallest time)
    if (head == nullptr || head->getEvent()->getTime() > e->getTime())
    {
        newNode->setNext(head);
        head = newNode;
        //cout << "event added at head" << endl;
        return;
    }

    // Case 2: Insert in the middle or at the end
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

   // delete prev->getEvent();
    delete prev;
}

void LinkedList::setHead(Node* head){
    this->head = head;
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

