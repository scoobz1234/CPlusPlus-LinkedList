#include "LinkedList.h"
using namespace std;

//constructor
LinkedList::LinkedList()
{
	this->headNode = NULL;
	this->listLength = 0;
	//cout << "List has been created" << endl;
}

//destructor
LinkedList::~LinkedList()
{
	cout << "List has been deleted" << endl;
}


void LinkedList::AddNode(int _data)
{
	Node* newNode = new Node(); //create a blank new node
	
	// if this is the first node in the list, then set the new node information to headnode and current node
	if (headNode == NULL) 
	{
		headNode = newNode;
	}
	
	newNode->data = _data;	//set the new nodes data...

	//if were adding to the end, then set the current node to the new nodes address...
	if (listLength >= 1)
	{
		if (currentNode->next == NULL)
		{
			newNode->next = NULL;
			currentNode->next = newNode;
		}
		//else were adding somewhere in the middle, so we need to set the next information accordingly...
		else
		{
			newNode->next = currentNode->next; //first set new nodes next node to the current nodes next node...
			currentNode->next = newNode; //now set the current nodes next to the new node address...
		}
	}

	currentNode = newNode;
	listLength++;

}

void LinkedList::RemoveNode(Node* node)
{
	cout << "Checking for node..." << endl;
	while (currentNode != node) 
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	cout << "Found node..." << endl;

	char choice;
	cout << "are you sure you want to delete node: " << node->data << " 'Y' or 'N'" << endl;
	cout << "-> ";
	cin >> choice;

	if (choice == 'Y' || choice == 'y') 
	{
		//we have reached our node...
		if (currentNode == node)
		{
			previousNode->next = currentNode->next;
			delete currentNode;
		}
		//now its deleted, set the currentNode to the previousNode.
		currentNode = previousNode;
		listLength--;
		PrintNodes();
	}
}

void LinkedList::PrintList()
{
	Node* current = headNode;

	cout << "\nThis list has " << listLength << " Nodes" << endl;

	for (int i = 0; i < listLength; i++) 
	{
		cout << i << ": " << current->data << endl;
		current = current->next;
	}

	cout << "-- END OF LIST --" << endl;
}

void LinkedList::IterateList()
{
	currentNode = headNode;

	PrintNodes();

	bool keepIterating = true;

	while (keepIterating)
	{
		int input;
		cin >> input;
		switch (input)
		{
		case 1:
			//set the previous node to the current node before we iterate forward...
			previousNode = currentNode;
			//if the next node isnt empty (end of list) then set the current node to the next node...
			if (currentNode->next != NULL)
			{
				currentNode = currentNode->next;
				PrintNodes();
			}
			else
			{
				cout << "You have reached the end of the list, I will iterate back to the Head node now..." << endl;
				previousNode = currentNode;
				currentNode = headNode;
				PrintNodes();
			}
			break;
		case 2:
			if (previousNode != NULL)
			{
				currentNode = previousNode;
				previousNode = NULL;
				PrintNodes();
			}
			else
			{
				cout << "You can only go back once!" << endl;
			}
			break;
		case 3:
			RemoveNode(currentNode);
			break;
		case 4:
			cout << "Let's add a node..." << "\nEnter a number to add" << endl;
			cout << "-> ";
			int choice;
			cin >> choice;
			AddNode(choice);
			cout << "Added " << choice << " sucessfully!" << endl;
			PrintNodes();
			break;
		case 5:
			keepIterating = false;
			break;
		}
	}
}

void LinkedList::PrintNodes()
{
	cout << "--------------------------" << endl;

	if (previousNode != NULL)
	{
		cout << "Previous Node: " << previousNode->data << endl;
	}

	cout << "Current Node: " << currentNode->data << endl;
	if (currentNode->next != NULL)
	{
		cout << "Next Node: " << currentNode->next->data << endl;
	}

	cout << "--------------------------" << endl;
}

Node* LinkedList::FindNode(int _data)
{
	currentNode = headNode;
	while (currentNode->data != _data) 
	{
		currentNode = currentNode->next;
		if (currentNode->next == NULL) 
		{
			//reached end of list, could not find...
			break;
		}
	}
	if (currentNode->data == _data) 
	{
		//data was found in list. return node...
		return currentNode;
	}
}

int LinkedList::FindMax() 
{
	int max = headNode->data;
	currentNode = headNode;
	while (currentNode->next != NULL) 
	{
		if (currentNode->data > max) 
		{
			max = currentNode->data;
		}
		currentNode = currentNode->next;
	}
	return max;
}

int LinkedList::FindMin() 
{
	int min = headNode->data;
	currentNode = headNode;
	while (currentNode->next != NULL) 
	{
		if (currentNode->data < min) 
		{
			min = currentNode->data;
		}
		currentNode = currentNode->next;
	}
	return min;
}


/// <summary>
/// SelectionSort
/// Worst Case - O(n^2)
/// </summary>
void LinkedList::SelectionSort() {

	// Iterate the list...
	Node* currNode = headNode;
	while (currNode) 
	{
		Node* min = currNode;
		Node* nextNode = currNode->next;

		//Iterate the unsorted sub list data...
		while (nextNode)
		{
			if (min->data > nextNode->data)
			{
				min = nextNode;
			}
			nextNode = nextNode->next;
		}
		// Swap the data of the nodes...
		int temp = currNode->data;
		currNode->data = min->data;
		min->data = temp;
		currNode = currNode->next;
	}
}

/// <summary>
/// Bubble Sort
/// Worst Case - O(n^2)
/// O(n) on a already sorted list.. (runs once)
/// </summary>
void LinkedList::BubbleSort()
{
	int swapped;
	Node* left; // always points to the start of the list... O(1)
	Node* right = NULL; // this points to the end of the list... O(1) 
	do 
	{
		swapped = 0;
		left = headNode; // set us at the beginning of the list...
		//while left->next is not null (end of list)
		while (left->next != right) 
		{
			//compare lefts data to nextnode data
			if (left->data > left->next->data) 
			{
				// swap the data for the nodes since left is greater than right...
				int temp = left->data;
				left->data = left->next->data;
				left->next->data = temp;
				swapped = 1;
			}
			left = left->next; // done with this level, moving on...
		}
		right = left;

	} while (swapped);
}

/// <summary>
/// Insertion Sort
/// Worst Case - O(n^2)
/// still better than Bubble and Selection
/// </summary>
void LinkedList::InsertionSort()
{
	
	Node* currentNode = headNode->next;

	while (currentNode != NULL)
	{
		int data = currentNode->data;
		int found = 0;
		Node* previousNode = headNode;

		while (previousNode != currentNode)
		{
			if (previousNode->data > currentNode->data && found == 0)
			{
				data = previousNode->data;
				previousNode->data = currentNode->data;
				found = 1;
				previousNode = previousNode->next;
			}
			else 
			{
				if (found == 1) 
				{
					int temp = data;
					data = previousNode->data;
					previousNode->data = temp;
				}
				previousNode = previousNode->next;
			}
		}
		previousNode->data = data;
		currentNode = currentNode->next;
	}
}

/// <summary>
/// Merge Sort
/// Worst Case - O(n log(n))
/// </summary>
void LinkedList::MergeSort(Node**head)
{
	Node* first = new Node();
	Node* second = new Node();
	Node* temp = new Node();
	first = *head;
	temp = *head;

	// Return if the list has less than two nodes...
	if (first == NULL || first->next == NULL) 
	{
		return;
	}
	else 
	{
		// Break the list into two halves as first and second...
		while (first->next != NULL) 
		{
			first = first->next;
			if (first->next != NULL) 
			{
				temp = temp->next;
				first = first->next;
			}
		}
		second = temp->next;
		temp->next = NULL;
		first = *head;
	}

	// Recursive mode... go...
	MergeSort(&first);
	MergeSort(&second);

	// Merge the two parts of the list into a sorted one...
	*head = mMerge(first, second);
}

Node* LinkedList::mMerge(Node* firstListHeadNode, Node* secondListHeadNode)
{
	Node* firstNode = new Node;
	Node* secondNode = new Node;
	Node* temp = new Node;

	// if the head node is empty on the first list return the second head node
	// and if the second list node is empty return the first list head node...
	if (firstListHeadNode == NULL) return secondListHeadNode;
	if (secondListHeadNode == NULL) return firstListHeadNode;

	//set firstNode to the head node of the first list...
	firstNode = firstListHeadNode;

	// Loop to iterate the second list, to merge the nodes into h1..
	while (secondListHeadNode != NULL) 
	{
		// Take head node of second list as secondNode...
		secondNode = secondListHeadNode;

		// Shift the second list head to the next...
		secondListHeadNode = secondListHeadNode->next;
		secondNode->next = NULL;

		// if the data value is lesser than the head of the first list add that node..
		if (firstListHeadNode->data > secondNode->data)
		{
			secondNode->next = firstListHeadNode;
			firstListHeadNode = secondNode;
			firstNode = firstListHeadNode;
			continue;
		}

		// Travers the first list...
	flag:
		if (firstNode->next == NULL)
		{
			firstNode->next = secondNode;
			firstNode = firstNode->next;
		}
		else if (firstNode->next->data <= secondNode->data)
		{
			firstNode = firstNode->next;
			goto flag;
		}
		else 
		{
			//insert the node as t2 data is lesser then the next node
			temp = firstNode->next;
			firstNode->next = secondNode;
			secondNode->next = temp;
		}
	}

	return firstListHeadNode;
}

Node* LinkedList::mGetEndNode(Node* currentNode) 
{
	while (currentNode != NULL && currentNode->next != NULL) 
	{
		currentNode = currentNode->next;
	}
	return currentNode;
}


void LinkedList::QuickSort() 
{
	headNode = mQuickSort(headNode, mGetEndNode(headNode));
}

Node* LinkedList::mQuickSort(Node* headNode, Node* endNode)
{
	//check if the list is empty... or there are only two nodes...
	if (!headNode || headNode == endNode) 
	{
		return headNode;
	}

	Node* newHeadNode = NULL;
	Node* newEndNode = NULL;

	// this is where we split the list, we pass a reference to the new head and new end
	// which will be updated in the partition function.
	Node* pivot = mSplit(headNode, endNode, &newHeadNode, &newEndNode);

	// Check if the pivot is the smallest element.
	if (newHeadNode != pivot) 
	{
		// Set the node before the pivot node as null...
		Node* temp = newHeadNode;
		while (temp->next != pivot) 
		{
			temp = temp->next;
		}
		temp->next = NULL;

		// Recursive for the list before the pivot node
		newHeadNode = mQuickSort(newHeadNode, temp);

		// change the next of the last node of the left half of this list to the pivot node
		temp = mGetEndNode(newHeadNode);
		temp->next = pivot;
	}

	//now do it for the second list...
	pivot->next = mQuickSort(pivot->next, newEndNode);

	return newHeadNode;
}

Node* LinkedList::mSplit(Node* head, Node* end, Node** newHead, Node** newEnd)
{
	// set the pivot node to the end node of this list
	Node* pivotNode = end;
	// we havent done anything so previous is null
	Node* previousNode = NULL;
	// the current node is the head node of this list
	Node* currentNode = head;
	// and the tail node or end node is the pivot node..
	Node* tailNode = pivotNode;

	// while were not at the end of the list...
	while (currentNode != pivotNode)
	{
		//if the current node is less than the pivot node
		if (currentNode->data < pivotNode->data)
		{
			if (*newHead == NULL)
			{
				*newHead = currentNode;
			}
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
		//if the current node is greater than the pivot node
		else
		{
			if (previousNode)
			{
				previousNode->next = currentNode->next;
			}
			Node* temp = currentNode->next;
			currentNode->next = NULL;
			tailNode->next = currentNode;
			tailNode = currentNode;
			currentNode = temp;
		}
	}

	// if the pivot data is the smallest element in the current list,
	// the pivot becomes the new headnode...
	if (*newHead == NULL) 
	{
		*newHead = pivotNode;
	}
	// update the new end to the current last node in the list...
	*newEnd = tailNode;

	// return the pivot node...
	return pivotNode;

}