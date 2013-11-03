#include "stdafx.h"

void NthElementAlgorithm::execute(int* first, int* mid, int* last){
	std::nth_element(first,mid,last);
}