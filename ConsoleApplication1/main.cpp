#include <iostream>
#include "LinkedList.h"
#include <Windows.h>

using namespace std;

//-- VARIABLES --//
bool isRunning = true;
LinkedList* intList = new LinkedList();
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


//-- FUNCTIONS --//
string TransformToUpper(string s);
void AddToListLoop();


int main(int argC, char** argV)
{
	bool invalid = false;
	while (isRunning) 
	{
		int choice;
		int validChoices[] = { 1,2,3,4 };
		if (invalid) 
		{
			SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | BACKGROUND_RED);
			cout << "INVALID INPUT, TRY AGAIN";
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		cout << "\n\nPlease select an option from the list\n"
				<< "----------------\n"
				<< "1. Add to list\n"
				<< "2. Print list\n"
				<< "3. Iterate List\n"
				<< "4. Exit\n"
				<< "----------------" << endl;
		cout << "-> ";
		cin >> choice;

		//here we are checking for valid input, if its not an integer it will fail.
		while (1)
		{
			if (cin.fail()) 
			{
				cout << "Invalid Selection, Try again!" << endl;
				cout << "-> ";
				cin.clear();
				cin.ignore();
				cin >> choice;
				for (int i : validChoices) 
				{
					if (choice == i) 
						break;
				}
			}
			if (!cin.fail()) 
			{
				break;
			}
		}

		switch (choice)
		{
		case 1:
			invalid = false;
			system("CLS");
			AddToListLoop();
			break;
		case 2:
			invalid = false;
			system("CLS");
			intList->PrintList();
			break;
		case 3:
			invalid = false;
			system("CLS");
			intList->IterateList();
			break;
		case 4:
			invalid = false;
			isRunning = false;
			break;
		default:
			cout << choice << " is an invalid selection, please try again!" << endl;
			invalid = true;
			system("CLS");
			break;
		}
	}


	return 0;
}

//this function transforms lower case strings to uppercase strings.
string TransformToUpper(string s) 
{
	string conv;

	for (int i = 0; i < s.size(); ++i)
		conv += (toupper(s[i]));

	return conv;
	
}

//this is the loop the user enters in order to input numbers into the
//linked list.
void AddToListLoop() 
{
	bool run = true;
	cout << "Type 'N' or 'NO' to finish at any time" << endl;
	while (run) 
	{
		string choice;
		cout << "Please Enter a number to add to the list" << endl;
		cout << "-> ";
		cin >> choice;

		//check if the user has typed N or NO to exit
		if(TransformToUpper(choice) == "N" || TransformToUpper(choice) == "NO")
		{
			run = false;
		}
		//else we just add the input to the list
		else
		{
			int choiceToInt = stoi(choice); //String To Int
			intList->AddNode(choiceToInt);
		}
	}
}