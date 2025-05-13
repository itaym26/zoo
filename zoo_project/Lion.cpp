#include "Lion.h"
Lion::Lion() {
	this->_animalType = 3;
	cout << "(Lion)Lion volume";
	cin >> this->_volume;
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