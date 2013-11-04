#include "stdafx.h"

int QuickSelectAlgorithm::partition(int* valueList, int left, int right)
{
    int pivotElement = valueList[right];
    
    while ( left < right )
    {
        while ( valueList[left] < pivotElement ){
            left++; 
		}
        while ( valueList[right] > pivotElement ){
            right--;
		}
        if ( valueList[left] == valueList[right] ){
            left++;
		} else if ( left < right ) {
            int temp = valueList[left];
            valueList[left] = valueList[right];
            valueList[right] = temp;
        }
    }
    return right;
}

int QuickSelectAlgorithm::getMedian(int* valueList, int left, int right, int k)
{
    if ( left == right ){
		return valueList[left];
	}

    int j = partition(valueList, left, right);
    int length = j - left + 1;

    if ( length == k ){
		return valueList[j];
	} else if ( k < length ){
		return getMedian(valueList, left, j - 1, k);
	} else {
		return getMedian(valueList, j + 1, right, k - length);
	}
}