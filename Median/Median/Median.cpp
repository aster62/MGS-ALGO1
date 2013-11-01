// Median.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "ValueList.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void sampleFromFileToCout(string fileName);

int _tmain(int argc, _TCHAR* argv[])
{

	Timer timer;

	timer.start();

	ValueList randomList(9);
	randomList.printList();

	ValueList fileList("input1.txt");
	fileList.printList();

	randomList.~ValueList();
	fileList.~ValueList();

	timer.stop();
	
	cout << "Total time elapsed: " << timer.getElapsedTimeInMilliSec() << " (ms)";

	cin.get();

	

	

	return 0;
}