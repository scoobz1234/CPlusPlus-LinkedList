#pragma once
#include "Node.h"
#include <iostream>

class LinkedList
{
public:

	LinkedList(); //constructor
	~LinkedList(); //destructor

	Node* headNode = NULL;
	Node* currentNode = NULL;
	Node* previousNode = NULL;

	int listLength = 0;

	void AddNode(int);
	void RemoveNode(Node*);
	void PrintList();
	void IterateList();
	void PrintNodes();

	Node* FindNode(int);
	int FindMax();
	int FindMin();

	void SelectionSort();
	void BubbleSort();
	void InsertionSort();
	void MergeSort(Node**);
	void QuickSort();

private:

	Node* mSplit(Node*, Node*, Node**, Node**);
	Node* mQuickSort(Node*, Node*);
	Node* mGetEndNode(Node*);
	Node* mMerge(Node*, Node*);
};

