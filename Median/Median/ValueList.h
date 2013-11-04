#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <istream>
#include <string>

class ValueList
{
public:
		 ValueList(std::string);
		 ValueList(int);
		 ~ValueList();
	int* getValuesArr();
	void shuffleValueArr();
	void printList();
	void initializeList(string);
	void initializeList(int);
private:
	int  quantity;
	int* testValues;
	void fillValueArr();
	int getListSize();
};