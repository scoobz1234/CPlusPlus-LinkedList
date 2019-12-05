#pragma once
#include "Node.h"
//#include <iostream>

class LinkedList
{
public:

	LinkedList(); //constructor
	~LinkedList(); //destructor

	Node* headNode = NULL;
	Node* currentNode = NULL;
	Node* previousNode = NULL;

	int listLength = 0;

	void AddNode(int data);

	void RemoveNode(Node* node);
	void PrintList();

	void IterateList();
	void PrintNodes();

	Node* FindNode(int data);
	int FindMax();
	int FindMin();

};

