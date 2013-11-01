// Median.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "ValueList.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

void sampleFromFileToCout(string fileName);

int _tmain(int argc, _TCHAR* argv[])
{
	ValueList createValues(50);
	int* valueList = createValues.getValuesArr();

	cout << "\n" << valueList[0];

	createValues.shuffleValueArr();

	cout << "\n" << valueList[0] << "\n";

	sampleFromFileToCout("input1.txt");
	
	cin.get();

	createValues.~ValueList();

	return 0;
}

void sampleFromFileToCout(string fileName) {
	string line;
	ifstream myfile (fileName);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) ){
			cout << line << endl;
		}
    myfile.close();
	} 
	else {
		cout << "Unable to open file"; 
	}

	return;
}