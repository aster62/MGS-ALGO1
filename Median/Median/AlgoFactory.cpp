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

int* AlgoFactory::quickSelect(int *first, int *last, int *k){
// Quickselect
	
	// return the kth smallest item

    if ( first == last ) return first;
    int* j = partition(first, last);
    int length = *j - *first + 1;
    if ( length == *k ) return j;
    else if (*k < length ) return quickSelect(first, j - 1, k);
    else  return quickSelect( j + 1, last, k - length);
}

void AlgoFactory::STLnth_element(int* first, int* mid, int* last){
	std::nth_element(first,mid,last);
}

int* AlgoFactory::partition(int* left, int* right){
	int pivot = *right;
    
	while ( left < right )
	{
		while ( *left < pivot )
			left++;
        
		while ( *right > pivot )
			right--;
        
		if ( *left == *right )
			left++;
		else if ( left < right ) {
			int tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
    
	return right;
}

