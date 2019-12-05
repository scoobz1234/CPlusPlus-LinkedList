#pragma once
#include <iostream>
#include <string>

class Node
{
public:
	//constructor...
	Node(int _intData, Node* _next);

	Node(){}; //default so we can create empty nodes...
	~Node() { std::cout << "Node Deleted" << std::endl; }

	int intData = NULL;

	Node* next = NULL;
};

