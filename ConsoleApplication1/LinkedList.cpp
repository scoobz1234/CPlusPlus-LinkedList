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
	
	newNode->intData = _data;	//set the new nodes data...

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
	cout << "are you sure you want to delete node: " << node->intData << " 'Y' or 'N'" << endl;
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
		cout << i << ": " << current->intData << endl;
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
		cout << "Previous Node: " << previousNode->intData << endl;
	}

	cout << "Current Node: " << currentNode->intData << endl;
	if (currentNode->next != NULL)
	{
		cout << "Next Node: " << currentNode->next->intData << endl;
	}

	cout << "--------------------------" << endl;
}

Node* LinkedList::FindNode(int _data)
{
	currentNode = headNode;
	while (currentNode->intData != _data) 
	{
		currentNode = currentNode->next;
		if (currentNode->next == NULL) 
		{
			//reached end of list, could not find...
			break;
		}
	}
	if (currentNode->intData == _data) 
	{
		//data was found in list. return node...
		return currentNode;
	}
}

int LinkedList::FindMax() 
{
	int max = headNode->intData;
	currentNode = headNode;
	while (currentNode->next != NULL) 
	{
		if (currentNode->intData > max) 
		{
			max = currentNode->intData;
		}
		currentNode = currentNode->next;
	}
	return max;
}

int LinkedList::FindMin() 
{
	int min = headNode->intData;
	currentNode = headNode;
	while (currentNode->next != NULL) 
	{
		if (currentNode->intData < min) 
		{
			min = currentNode->intData;
		}
		currentNode = currentNode->next;
	}
	return min;
}
