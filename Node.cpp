#include "Node.h"

//constructor 
Node::Node(Event* event, Node* n) : event(event) , next(n) {}

//Instance mehods
Node* Node::getNext()
{
    return next;
}

void Node::print()
{
    
}