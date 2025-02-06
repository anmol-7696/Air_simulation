#include "LinkedList.h"
#include "Event.h"

LinkedList::LinkedList(){
    Node* head = nullptr;
}

void LinkedList::orderedInsert(Event* e) {
    Node* newNode = new Node(e, nullptr);

    // Case 1: Empty list OR inserting at the head (smallest time)
    if (head == nullptr || head->getEvent()->getTime() >= e->getTime()) {
        newNode->setNext(head); // Insert at the beginning
        head = newNode;
        return;
    }

    // Case 2: Insert in the middle or at the end
    Node* curr = head;
    while (curr->getNext() != nullptr && curr->getNext()->getEvent()->getTime() < e->getTime()) {
        curr = curr->getNext(); // Move forward
    }

    // Insert new node after `curr`
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
}
