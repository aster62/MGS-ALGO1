#include "stdafx.h"
using namespace std;

int RandomizedSelectAlgorithm::random_partition(int* valueList, int start, int end)
{
    int pivotIdx = start + rand() % (end-start+1);
    int pivot = valueList[pivotIdx];
    swap(valueList[pivotIdx], valueList[end]); //swap pivot and last element
    pivotIdx = end;
    int i = start -1;
 
    for(int j=start; j<=end-1; j++)
    {
        if(valueList[j] <= pivot)
        {
            i = i+1;
            swap(valueList[i], valueList[j]);
        }
    }
 
    swap(valueList[i+1], valueList[pivotIdx]);
    return i+1;
}
 
int RandomizedSelectAlgorithm::random_selection(int* valueList, int start, int end, int k)
{
    if(start == end)
        return valueList[start];
 
    if(start < end)
    {
 
    int mid = random_partition(valueList, start, end);
    int i = mid - start + 1;
    if(i == k)
        return valueList[mid];
    else if(k < i)
        return random_selection(valueList, start, mid-1, k);
    else 
        return random_selection(valueList, mid+1, end, k-i);
    }
}

int RandomizedSelectAlgorithm::getMedian(int* arr, int start, int end, int k){
	return random_selection(arr, start, end, k);
}