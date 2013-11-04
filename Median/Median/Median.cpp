// Median.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

void printUsage();
void printUsage(string);

int main(int argc, char* argv[])
{
	ValueList valueList;

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

	if(listSize < 1){
		printUsage("Missing argument.");
		return -1;
	}

	AlgoFactory algoFactory;
	Timer timer;

	int* ranList = valueList.getValuesArr();

	timer.start();
	NthElementAlgorithm nth;
	cout << "Nth Element: \n";
	nth.execute(ranList, ranList + listSize/2, ranList + listSize);
	timer.stop();
	cout << "Median: " << *(ranList+listSize/2) << "\n";
	cout << "Time: " << timer.getElapsedTimeInMilliSec() << " (ms) \n\n";
	
	valueList.shuffleValueArr();

	timer.start();
	cout << "Randomized Select: \n";
	RandomizedSelectAlgorithm rsa;
	int rsaMedian = rsa.getMedian(ranList, 0, listSize-1, (listSize/2)+1);
	timer.stop();
	cout << "Median: " << rsaMedian << "\n";
	cout << "Time: " << timer.getElapsedTimeInMilliSec() << " (ms) \n\n";

	valueList.shuffleValueArr();

	timer.start();
	cout << "QuickSort + Median: \n";
	QuicksortAlgorithm quickSort;
	int qs = quickSort.getMedian(ranList, 0, listSize);
	timer.stop();
	cout << "Median: " << rsaMedian << "\n";
	cout << "Time: " << timer.getElapsedTimeInMilliSec() << " (ms) \n\n";

	//algoFactory.quicksort(ranList,ranList + 9); // nicht richtig
	//int * last = algoFactory.quickSelect(ranList,ranList +11, ranList); //nicht richtig
	//algoFactory.STLnth_element(ranList, ranList + 5, ranList + 11); // funktioniert
	
	//randomList.printList();
	//cout << "Median is: "<< *last  << "\n";
	
	//randomList.printList();

	//ValueList fileList("input100.txt");
	//fileList.printList();	

	cin.get();

	return 0;
}

void printUsage(string message){

	if (!message.empty()){
		cout << "Error: " << message << "\n";
	}
	cout << "USAGE: Median [--load <inputFile>, --random <listSize>] \n";
	cout << "<ENTER> to exit the program. \n";
	cin.get();
}

void printUsage() {

	printUsage("");
}