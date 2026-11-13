#include "Insect.h"
Insect::Insect() : _numOflegs(0) {
	this->_animalType = 2;
	cout << "(Insect) Insect's number of legs:";
	if (!(cin >> this->_numOflegs)) throw "invalid leg count";
	cout << "(Insect)Insect constructed" << endl;
}
Insect::~Insect(){
	cout << "(Insect)Insect destroyed" << endl;
}
void Insect::print()const {
	Animal::print();
	cout << "(Insect)Insect number of legs:" << this->_numOflegs<< endl;
}
void Insect::makeNoise() const {
	cout << "(Insect) Insect nois...zzz..." << endl;
}

// Retain the original misspelled entry point for existing callers.
void Insect::makeNose() const { makeNoise(); }
