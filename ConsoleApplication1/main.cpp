#include <iostream>
#include "LinkedList.h"
#include <Windows.h>
#include <fstream>
#include <boost/foreach.hpp>
#include <chrono>

using namespace std;

//-- VARIABLES --//
bool isRunning = true;
LinkedList* intList = new LinkedList();
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


//-- FUNCTIONS --//
string TransformToUpper(string s);
void AddToListLoop();
void AddArrToList();
int* GetFile();


int main(int argC, char** argV)
{
	bool invalid = false;


	for (int i = 0; i < 6; i++) 
	{
		AddArrToList();
		auto start = std::chrono::high_resolution_clock::now();
		//intList->MergeSort(&intList->headNode);
		//intList->QuickSort();
		//intList->BubbleSort();
		intList->SelectionSort();
		//intList->InsertionSort();
		auto stop = std::chrono::high_resolution_clock::now();
		auto durationSelection = chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		cout << durationSelection.count() << " nanoseconds" << endl;
		intList = new LinkedList();
	}

	//while (isRunning) 
	//{
	//	int choice;
	//	int validChoices[] = { 1,2,3,4 };
	//	if (invalid) 
	//	{
	//		SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | BACKGROUND_RED);
	//		cout << "INVALID INPUT, TRY AGAIN";
	//		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	//	}
	//	cout << "\n\nPlease select an option from the list\n"
	//			<< "----------------\n"
	//			<< "1. Add to list\n"
	//			<< "2. Print list\n"
	//			<< "3. Iterate List\n"
	//			<< "4. Add Array From File\n"
	//			<< "5. Selection Sort\n"
	//			<< "6. Bubble Sort\n"
	//			<< "7. Insert Sort\n"
	//			<< "8. Merge Sort\n"
	//			<< "9. Quick Sort\n"
	//			<< "10. Exit\n"
	//			<< "----------------" << endl;
	//	cout << "-> ";
	//	cin >> choice;

	//	//here we are checking for valid input, if its not an integer it will fail.
	//	while (1)
	//	{
	//		if (cin.fail()) 
	//		{
	//			cout << "Invalid Selection, Try again!" << endl;
	//			cout << "-> ";
	//			cin.clear();
	//			cin.ignore();
	//			cin >> choice;
	//			for (int i : validChoices) 
	//			{
	//				if (choice == i) 
	//					break;
	//			}
	//		}
	//		if (!cin.fail()) 
	//		{
	//			break;
	//		}
	//	}
	//	auto start = chrono::high_resolution_clock::now();
	//	auto stop = chrono::high_resolution_clock::now();
	//	switch (choice)
	//	{
	//	case 1:
	//		invalid = false;
	//		system("CLS");
	//		AddToListLoop();
	//		break;
	//	case 2:
	//		invalid = false;
	//		system("CLS");
	//		intList->PrintList();
	//		break;
	//	case 3:
	//		invalid = false;
	//		system("CLS");
	//		intList->IterateList();
	//		break;
	//	case 4:
	//		invalid = false;
	//		system("CLS");
	//		AddArrToList();
	//		break;
	//	case 5:
	//		invalid = false;
	//		system("CLS");
	//		start = std::chrono::high_resolution_clock::now();
	//		intList->SelectionSort();
	//		stop = std::chrono::high_resolution_clock::now();
	//		auto durationSelection = chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	//		cout << durationSelection.count() << " milliseconds" << endl;
	//		break;
	//	case 6:
	//		invalid = false;
	//		system("CLS");
	//		start = std::chrono::high_resolution_clock::now();
	//		intList->BubbleSort();
	//		stop = std::chrono::high_resolution_clock::now();
	//		auto durationBubble = chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	//		cout << durationBubble.count() << " milliseconds" << endl;
	//		break;
	//	case 7:
	//		invalid = false;
	//		system("CLS");
	//		start = std::chrono::high_resolution_clock::now();
	//		intList->InsertionSort();
	//		stop = std::chrono::high_resolution_clock::now();
	//		auto durationInsert = chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	//		cout << durationInsert.count() << " milliseconds" << endl;
	//		break;
	//	case 8:
	//		invalid = false;
	//		system("CLS");
	//		start = std::chrono::high_resolution_clock::now();
	//		intList->MergeSort(&intList->headNode);
	//		stop = std::chrono::high_resolution_clock::now();
	//		auto durationMerge = chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	//		cout << durationMerge.count() << " milliseconds" << endl;
	//		break;
	//	case 9:
	//		invalid = false;
	//		system("CLS");
	//		start = std::chrono::high_resolution_clock::now();
	//		intList->QuickSort();
	//		stop = std::chrono::high_resolution_clock::now();
	//		auto durationQuick = chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
	//		cout << durationQuick.count() << " milliseconds" << endl;
	//		break;
	//	case 10:
	//		invalid = false;
	//		isRunning = false;
	//		break;
	//	case 11:
	//		invalid = false;
	//		system("CLS");
	//		intList = new LinkedList();
	//	default:
	//		cout << choice << " is an invalid selection, please try again!" << endl;
	//		invalid = true;
	//		system("CLS");
	//		break;
	//	}
	//}


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

//this is the loop the user enters in order to input numbers into the
//linked list.
void AddArrToList()
{
	int* arr;
	arr = GetFile();
	int size = 1000000;

	for (int i = 0; i < size; i++) 
	{
		intList->AddNode(arr[i]);
		//cout << arr[i] << " Added..." << endl;
	}
}

int* GetFile() 
{
	string fileName = "C:\\Users\\Stephen\\Desktop\\num1000000.dat";
	int* arr;
	int tmp;
	int count = 0;

	ifstream file(fileName);
	while (file >> tmp)
	{
		count++;
	}

	arr = new int[count];
	file.close();

	file.open(fileName);
	int i = 0;
	while (file >> tmp)
	{
		arr[i++] = tmp;
	}

	file.close();

	return arr;
}