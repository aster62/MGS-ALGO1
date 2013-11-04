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
		 ValueList(std::string);
		 ValueList(int);
		 ~ValueList();
	int* getValuesArr();
	void shuffleValueArr();
	void printList();
	void initializeList(std::string);
	void initializeList(int);
	int  getListSize();
private:
	int  quantity;
	int* testValues;
	void fillValueArr();
	
};