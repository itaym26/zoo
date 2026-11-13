#include "Lion.h"
Lion::Lion() : _volume(0) {
	this->_animalType = 3;
	cout << "(Lion)Lion volume";
	if (!(cin >> this->_volume)) throw "invalid volume";
	cout << "(Lion)Lion constructed"<<endl;
}
Lion:: ~Lion() {
	cout << "(lion)Lion destroyed" << endl;
}
void Lion::print()const {
	Mammel::print();//print the name of the animal
	cout << "(Lion)Lion's volume:" << this->_volume << endl;
}
void Lion::makeNoise()const{
	cout << "(Lion)Lion nois...zzz.." << endl;
}
