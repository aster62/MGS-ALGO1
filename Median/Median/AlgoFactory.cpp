#include "AlgoFactory.h"
using namespace std;

AlgoFactory::AlgoFactory(){

}

AlgoFactory::~AlgoFactory(){

}

void AlgoFactory::quicksort(int *left, int *right){
	int *i = left; // left Pointer
	int *j = right;// right Pointer
	int temp;
	int pivotElement = *(left + ((right - left) / 2));// PivotElement is in the middle

	// aslong as the two pointers don't cross eachother 
	do{ 
		while(*i < pivotElement){
			i++;
		}
		while(*j > pivotElement){
			j--;
		}
		if(i <= j){
			temp = *i;
			*i = *j;
			*j = temp;
		}

	}while(++i <= --j);
	//recursive call
	if(left < j){
		quicksort(left, j);
	}
	if(i < right){
		quicksort( i, right);
	}
}

int AlgoFactory::randomizedSelect(int* randomList, int a, int b, int c){
	return a;
}

void AlgoFactory::medianLit(int* randomList){
// Quickselect

}

void AlgoFactory::STLnth_element(int* randomList){

}

