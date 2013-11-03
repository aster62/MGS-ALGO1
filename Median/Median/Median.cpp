// Median.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

void sampleFromFileToCout(string fileName);

int _tmain(int argc, _TCHAR* argv[])
{
	AlgoFactory algoFactory;
	Timer timer;
	ValueList randomList(11);
	randomList.printList();
	int *ranList = randomList.getValuesArr();

	NthElementAlgorithm nth;
	BaseAlgorithm * baseNth = &nth;

	cout << "getInt: " << baseNth->getInt() << "\n";
	cout << "findMedian: " << baseNth->findMedian() << "\n";

	timer.start();
	//algoFactory.quicksort(ranList,ranList + 9); // nicht richtig
	//int * last = algoFactory.quickSelect(ranList,ranList +11, ranList); //nicht richtig
	//algoFactory.STLnth_element(ranList, ranList + 5, ranList + 11); // funktioniert
	timer.stop();
	randomList.printList();
	//cout << "Median is: "<< *last  << "\n";
	

	//ValueList fileList("input100.txt");
	//fileList.printList();	
	
	cout << "Total time elapsed: " << timer.getElapsedTimeInMilliSec() << " (ms) \n";

	cin.get();

	

	

	return 0;
}