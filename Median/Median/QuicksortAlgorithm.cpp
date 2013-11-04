#include "stdafx.h"

void QuicksortAlgorithm::quickSort(int* valueList , int left, int right) {
	
	int i = left;
	int j = right;
	int temp;
    
    int pivotElement = valueList[(left + right) / 2];
 
    while (i <= j) {
        while (valueList[i] < pivotElement){
                i++;
		}
        while (valueList[j] > pivotElement){
                j--;
		}
        if (i <= j) {
            temp = valueList[i];
            valueList[i] = valueList[j];
            valueList[j] = temp;
            i++;
            j--;
        }
    };

    if (left < j)
        quickSort(valueList, left, j);
    if (i < right)
        quickSort(valueList, i, right);
}

int QuicksortAlgorithm::getMedian(int* valueList, int left, int right){
	quickSort(valueList, left, right);
	return valueList[(right-left)/2];

}