#include "Insect.h"
Insect::Insect() {
	this->_animalType = 2;
	cout << "(Insect) Insect's number of legs:";
	cin >> this ->_numOflegs;
	cout << "(Insect)Insect constructed" << endl;
}
Insect::~Insect(){
	cout << "(Insect)Insect destroyed" << endl;
}
void Insect::print()const {
	Animal::print();
	cout << "(Insect)Insect number of legs:" << this->_numOflegs<< endl;
}
void Insect::makeNose() const {
	cout << "(Insect) Insect nois...zzz..." << endl;
}
