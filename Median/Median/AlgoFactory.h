#include "stdafx.h"

class AlgoFactory
{
public:
	AlgoFactory();
	~AlgoFactory();

	void quicksort(int*);
	int randomizedSelect(int*, int, int, int);
	void medianLit(int*);
	void STLnth_element(int*);
private:

};

AlgoFactory::AlgoFactory()
{
}

AlgoFactory::~AlgoFactory()
{
}