#include "Animal.h"

Animal::Animal() : _animalType(0), _animalAge(0) {
	cout << "(Animal)Enter the animal's name:";
	if (!(cin >> this->_animalName)) throw "invalid animal name";
	cout << "(Animal) ENTER THE ANIMAL'S AGE:";
	if (!(cin >> this->_animalAge)) throw "invalid animal age";
	if (this->_animalAge < 0) {
		this->_animalAge = 1;
			throw "age is out of rang";
	}
	this->_animalType = 0;
	cout << "(Animal) Animal constructed" << endl;
}
Animal::~Animal() {
	cout<<"(Animal)Animal destroyed"<<endl;		
}
void Animal:: print()const {
	cout << "(Animal) animal's name:" << this->_animalName << endl;
	cout << "(Animal)Animal's age:" << this->_animalAge << endl;
}
void Animal::makeNoise()const {
	cout << "(Animal)Animal's nois...zzz..."<<endl;
}
