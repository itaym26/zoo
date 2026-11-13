#include "Fly.h"
Fly::Fly() : _lifeTime(0) {
	this->_animalType = 5;
	cout << "(Fly) Fly life time";
	if (!(cin >> this->_lifeTime)) throw "invalid lifetime";
	cout << "(Fly)Fly constructed" << endl;
}
Fly:: ~Fly() {
	cout << "(Fly)Fly destroyed" << endl;
}
void Fly::print()const {
	Insect::print();//print the name of the animal
	cout << "(Fly) Fly's life time:" << this->_lifeTime << endl;
}
void Fly::makeNoise()const {
	cout << "(Fly) Fly nois...zzz.." << endl;
}
