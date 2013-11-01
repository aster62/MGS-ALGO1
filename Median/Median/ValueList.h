#include "stdafx.h"
#include <algorithm>
#include <iostream>

class ValueList
{
public:
		 ValueList(int);
		 ~ValueList();
	int* getValuesArr();
	void shuffleValueArr();
private:
	int  quantity;
	int* testValues;
	void fillValueArr();
	
};