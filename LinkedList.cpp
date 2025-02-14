#include "LinkedList.h"
#include "Event.h"

#include "iostream"

using namespace std;

LinkedList::LinkedList(){
    Node* head = nullptr;
}

void LinkedList::orderedInsert(Event* e) {
    Node* newNode = new Node(e, nullptr);

    // Case 1: Empty list OR inserting at the head (smallest time)
    if (head == nullptr || head->getEvent()->getTime() > e->getTime()) {
        newNode->setNext(head);
        head = newNode;
        return;
    }

    // Case 2: Insert in the middle or at the end
    Node* curr = head;
    while (curr->getNext() != nullptr && 
           curr->getNext()->getEvent()->getTime() < e->getTime()) {
        curr = curr->getNext();  // Move forward
    }

    // If time is the same, sort by ATC ID (higher ATC ID goes later)
    while (curr->getNext() != nullptr && 
           curr->getNext()->getEvent()->getTime() == e->getTime() && 
           curr->getNext()->getEvent()->getPlane()->getAtc() < e->getPlane()->getAtc()) {
        curr = curr->getNext();
    }

    // Insert new node after `curr`
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
}


bool LinkedList::isEmpty(){
    return head == nullptr;
}

Node* LinkedList::getHead(){
    return head;
}

void LinkedList::deleteHead() {
    if (head == nullptr) {  
        return; 
    }

    Node* prev = head;  // Store the current head
    head = head->getNext(); // Move head to the next node
    delete prev;
}

