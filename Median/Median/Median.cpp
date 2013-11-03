// Median.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;

void sampleFromFileToCout(string fileName);

int _tmain(int argc, _TCHAR* argv[])
{
	AlgoFactory algoFactory;
	Timer timer;


	ValueList randomList(1000000);
	int* ranList = randomList.getValuesArr();

	NthElementAlgorithm nth;
	BaseAlgorithm * baseNth = &nth;

	timer.start();
	nth.execute(ranList, ranList + 500000, ranList + 1000000);
	timer.stop();
	cout << "Nth Element: " << timer.getElapsedTimeInMilliSec() << " (ms) \n";


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