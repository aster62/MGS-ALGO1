#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>

class ValueList
{
public:
		 ValueList();
		 ValueList(std::string);		// Starts the initialization of an array from a file
		 ValueList(int);				// Starts the initialization of an array with x elements
		 ~ValueList();
	int* getValuesArr();				// Returns the pointer to the array
	void shuffleValueArr();				// Random shuffles the array
	void printList();					// prints the contents of the array to stdout
	void initializeList(std::string);	// Initializes the array from a file
	void initializeList(int);			// Initializes the array with x elements
	int  getListSize();					// Returns the maximum bound of the array
	void fillValueArr();				// Fills the array with random elements
private:
	int  quantity;						// Number of elements max. stored in the array
	int* testValues;					// int array for the testValues
	
	
};