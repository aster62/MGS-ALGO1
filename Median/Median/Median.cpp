// Median.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "ValueList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void sampleFromFileToCout(string fileName);

int _tmain(int argc, _TCHAR* argv[])
{
	ValueList randomList(9);
	randomList.printList();

	ValueList fileList("input1.txt");
	fileList.printList();
	
	cin.get();

	randomList.~ValueList();
	fileList.~ValueList();

	return 0;
}