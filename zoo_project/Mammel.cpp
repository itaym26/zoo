#include "Mammel.h"

Mammel::Mammel() {
	this->_animalType = 1;
	cout << "(Mammel)Mammel got milke (y/n)? ";
	char t;
	cin >> t;
	if (t == 'Y' || t == 'y')
		this->_gotMilk = true;
	else
		this->_gotMilk = false;
	cout << "(Mammel) Mammel constructed" << endl;
}
Mammel::~Mammel(){
	cout << "(Mammel) Mammel destroyed" << endl;
}
void Mammel:: print()const {
	Animal::print();//print the name of the animal
	if (this->_gotMilk)
		cout << "(Mammel) got milk" << endl;
	else
		cout << "(Mammel) Mammel didn't get milk" << endl;
}
void Mammel::makeNoise()const {
	cout << "(Mammel)Mammels nois...zzz..." << endl;
}