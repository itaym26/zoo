#include "Horse.h"
Horse::Horse() : _speed(0) {
	this->_animalType = 4;
	cout << "(Horse) Horse speed";
	if (!(cin >> this->_speed)) throw "invalid speed";
	cout << "(Horse) Horse constructed" << endl;
}
Horse:: ~Horse() {
	cout << "(Horse)Horse destroyed" << endl;
}
void Horse::print()const {
	Mammel::print();//print the name of the animal
	cout << "(Horse) Horse's speed:" << this->_speed << endl;
}
void Horse::makeNoise()const {
	cout << "(Horse) Horse nois...zzz.." << endl;
}
