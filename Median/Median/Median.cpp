// Median.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

void sampleFromFileToCout(string fileName);

int _tmain(int argc, _TCHAR* argv[])
{

	int listSize = 1000000;

	AlgoFactory algoFactory;
	Timer timer;

	ValueList randomList(listSize);
	int* ranList = randomList.getValuesArr();

	timer.start();
	NthElementAlgorithm nth;
	cout << "Nth Element: \n";
	nth.execute(ranList, ranList + listSize/2, ranList + listSize);
	timer.stop();
	cout << "Median: " << *(ranList+listSize/2) << "\n";
	cout << "Time: " << timer.getElapsedTimeInMilliSec() << " (ms) \n\n";
	
	randomList.shuffleValueArr();

	timer.start();
	cout << "Randomized Select: \n";
	RandomizedSelectAlgorithm rsa;
	int rsaMedian = rsa.getMedian(ranList, 0, listSize-1, (listSize/2)+1);
	timer.stop();
	cout << "Median: " << rsaMedian << "\n";
	cout << "RandomizedSelectAlgorithm " << timer.getElapsedTimeInMilliSec() << " (ms) \n";

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