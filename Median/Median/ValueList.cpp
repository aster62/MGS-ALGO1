#include "stdafx.h"
using namespace std;

ValueList::ValueList(){
	quantity = -1;
}

ValueList::ValueList(int quantity){
	initializeList(quantity);
}

ValueList::ValueList(string fileName){
	initializeList(fileName);
}

// Initializes a list with a given size
void ValueList::initializeList(int quantity){
	this->quantity = quantity;
	fillValueArr();
	shuffleValueArr();
}

// Reads the size of the list and the numbers from a given file
void ValueList::initializeList(string fileName){
	quantity = 0;

	int valueCounter = 0;
	string firstLine;
	string line;
	ifstream myFile (fileName);
	if (myFile.is_open())
	{
		getline(myFile, firstLine);

		quantity = stoi(firstLine);

		testValues = new int[quantity];

		while ( getline (myFile,line) ){
			testValues[valueCounter] = stoi(line);
			valueCounter++;
		}

    myFile.close();

	} 
	else {
		cout << "Unable to open file"; 
	}
}

ValueList::~ValueList(){

}

// Fills the initialized Array with random numbers
void ValueList::fillValueArr(){
	testValues = new int[quantity];
	srand (time(NULL));
	for(int i = 0; i < quantity; i++){
		testValues[i] = rand() % quantity +1;
	}
}

// Simple implementation of a random shuffle on the ValueList array
void ValueList::shuffleValueArr(){
	std::random_shuffle(&testValues[0],&testValues[quantity]);
}

// Returns the pointer to the array
int* ValueList::getValuesArr(){
	return testValues;
}

// Prints the contents of the array
void ValueList::printList(){
	for(int i = 0; i<quantity;i++){
		cout << testValues[i] << "; ";
	}
	cout << "\n";
}

int ValueList::getListSize(){
	return quantity;
}

void ValueList::freeResources(){
	delete testValues;
	testValues = NULL;
}