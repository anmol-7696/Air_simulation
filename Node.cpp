#include "Node.h"

//constructor 
Node::Node(Event* event, Node* n) : event(event) , next(n) {}

//Instance mehods
Node* Node::getNext()
{
    return next;
}

Event* Node::getEvent()
{
    return event;
}

void Node::setNext(Node* n)
{
    this->next = n;
}

void Node::setEvent(Event* e){
    this->event = e;
}

Node::~Node()
{
     delete this->event;
}