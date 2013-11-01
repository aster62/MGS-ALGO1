// Median.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "ValueList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ValueList createValues(50);
	int* valueList = createValues.getValuesArr();

	std::cout << "\n" << valueList[0];

	createValues.shuffleValueArr();

	std::cout << "\n" << valueList[0];

	std::cin.get();

	createValues.~ValueList();

	return 0;
}

