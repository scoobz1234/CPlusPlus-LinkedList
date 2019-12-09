#include "Node.h"

//constructor of the node being created...
Node::Node(int _intData, Node* _next) 
{

	_intData != NULL ? data = _intData : data = NULL; //ternary to check which type of node were creating...

	next = _next;
}



