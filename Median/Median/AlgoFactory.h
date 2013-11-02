#include "stdafx.h"
#include <algorithm>
class AlgoFactory
{
public:
	AlgoFactory();
	~AlgoFactory();

	void quicksort(int*, int*);
	int randomizedSelect(int*, int, int, int);
	int* quickSelect(int*, int*,int*);
	void STLnth_element(int*, int*, int*);
private:
	int* partition(int*,int*);

};