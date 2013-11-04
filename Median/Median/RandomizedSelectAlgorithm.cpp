#include "stdafx.h"
using namespace std;

int RandomizedSelectAlgorithm::random_partition(int* valueList, int left, int right)
{
    int pivotIndex = left + rand() % (right-left+1);
    int pivotElement = valueList[pivotIndex];

	int temp;

	temp = valueList[pivotIndex];
	valueList[pivotIndex] = valueList[right];
	valueList[right] = temp;

    pivotIndex = right;
    int i = left -1;
 
    for(int j=left; j<=right-1; j++)
    {
        if(valueList[j] <= pivotElement)
        {
            i = i+1;

			temp = valueList[i];
			valueList[i] = valueList[j];
			valueList[j] = temp;
        }
    }

	temp = valueList[i+1];
	valueList[i+1] = valueList[pivotIndex];
	valueList[pivotIndex] = temp;

    return i+1;
}
 
int RandomizedSelectAlgorithm::random_selection(int* valueList, int left, int right, int k)
{
    if(left == right)
        return valueList[left];
 
    if(left < right)
    {
 
    int mid = random_partition(valueList, left, right);
    int i = mid - left + 1;
    if(i == k)
        return valueList[mid];
    else if(k < i)
        return random_selection(valueList, left, mid-1, k);
    else 
        return random_selection(valueList, mid+1, right, k-i);
    }
}

int RandomizedSelectAlgorithm::getMedian(int* valueList, int left, int right, int k){
	return random_selection(valueList, left, right, k);
}