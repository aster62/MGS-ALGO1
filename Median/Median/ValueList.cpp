#include "ValueList.h"

ValueList::ValueList(int quantity){
	this->quantity = quantity;
	fillValueArr();
	shuffleValueArr();
	for(int i = 0; i<quantity;i++){
		std::cout << testValues[i] << "; ";
	}
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