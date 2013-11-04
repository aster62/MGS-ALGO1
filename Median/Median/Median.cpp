// Median.cpp : Defines the entry point of the program
// Takes two arguments: --load <fileName> loads a file containing random numbers.
// --random <int> generates a list of random numbers with size x.
// Executes defined algorithms and returns both the resulted median and the execution time.
//
#include "stdafx.h"

using namespace std;

void printUsage();
void printUsage(string);

int main(int argc, char* argv[])
{
	ValueList valueList;

	// Process the command line arguments

	for(int i = 1; i < argc; i++) {
		if ( (strcmp(argv[i], "--load") == 0) && (i+1 < argc)){
			valueList.initializeList(argv[i+1]);
			i++;
		} 
		else if ( (strcmp(argv[i], "--random") == 0) && (i+1 < argc))
		{
			valueList.initializeList(stoi(argv[i+1]));
			i++;
		}
		else
		{
			printUsage();
			return -1;
		}
	}

	int listSize = valueList.getListSize();

	if(listSize == -1){
		printUsage("Missing argument.");
		return -1;
	}

	Timer timer;

	int* ranList = valueList.getValuesArr();

	// Execute and measure Nth-Element Algorithm

	timer.start();
	NthElementAlgorithm nth;
	cout << "Nth Element: \n";
	int nthMedian = nth.getMedian(ranList, ranList + listSize/2, ranList + listSize);
	timer.stop();
	cout << "Median: " << nthMedian << "\n";
	cout << "Time: " << timer.getElapsedTimeInMilliSec() << " (ms) \n\n";
	
	valueList.shuffleValueArr();

	// Execute and measure Randomized-Select Algorithm

	timer.start();
	cout << "Randomized Select: \n";
	RandomizedSelectAlgorithm rsa;
	int rsaMedian = rsa.getMedian(ranList, 0, listSize-1, (listSize/2)+1);
	timer.stop();
	cout << "Median: " << rsaMedian << "\n";
	cout << "Time: " << timer.getElapsedTimeInMilliSec() << " (ms) \n\n";

	valueList.shuffleValueArr();

	// Execute and measure Quicksort Algorithm

	timer.start();
	cout << "QuickSort + Median: \n";
	QuicksortAlgorithm quickSort;
	int quickSortMedian = quickSort.getMedian(ranList, 0, listSize-1);
	timer.stop();
	cout << "Median: " << quickSortMedian << "\n";
	cout << "Time: " << timer.getElapsedTimeInMilliSec() << " (ms) \n\n";

	valueList.shuffleValueArr();

	// Execute and measure Quickselect Algorithm

	timer.start();
	cout << "QuickSelect: \n";
	QuickSelectAlgorithm quickSelect;
	int quickSelectMedian = quickSelect.getMedian(ranList, 0, listSize-1, ((listSize)/2)+1);
	timer.stop();
	cout << "Median: " << quickSelectMedian << "\n";
	cout << "Time: " << timer.getElapsedTimeInMilliSec() << " (ms) \n\n";

	cin.get();

	return 0;
}

// Prints a usage text and an additional error message.
void printUsage(string message){

	if (!message.empty()){
		cout << "Error: " << message << "\n";
	}
	cout << "USAGE: Median [--load <inputFile>, --random <listSize>] \n";
	cout << "<ENTER> to exit the program. \n";
	cin.get();
}

// Prints a usage text.
void printUsage() {

	printUsage("");
}