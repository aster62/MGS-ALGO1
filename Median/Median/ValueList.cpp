#include "ValueList.h"
using namespace std;

ValueList::ValueList(int quantity){
	this->quantity = quantity;
	fillValueArr();
	shuffleValueArr();
}

ValueList::ValueList(string fileName){
	
	quantity = 0;

	int valueCounter = 0;
	string firstLine;
	string line;
	ifstream myFile (fileName);
	if (myFile.is_open())
	{
		getline(myFile, firstLine);

		quantity = stoi(firstLine);

		testValues = new int[quantity];

		while ( getline (myFile,line) ){
			testValues[valueCounter] = stoi(line);
			valueCounter++;
		}

    myFile.close();

	} 
	else {
		cout << "Unable to open file"; 
	}

	//Test
}

ValueList::~ValueList(){

	delete testValues;
	testValues = NULL;
}

void ValueList::fillValueArr(){
	testValues = new int[quantity];
	for(int i = 0; i < quantity; i++){
		testValues[i] = i ;
		//testValues[i] = rand() % quantity;
	}
}

void ValueList::shuffleValueArr(){
	std::random_shuffle(&testValues[0],&testValues[quantity]);
}

int* ValueList::getValuesArr(){
	return testValues;
}

void ValueList::printList(){
	for(int i = 0; i<quantity;i++){
		cout << testValues[i] << "; ";
	}
	cout << "\n";
}