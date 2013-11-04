#include "stdafx.h"

void NthElementAlgorithm::execute(int* first, int* mid, int* last){
	std::nth_element(first,mid,last);
}

int NthElementAlgorithm::getMedian(int* first, int* mid, int* last){
	execute(first, mid, last);
	return first[(last-first)/2];
}