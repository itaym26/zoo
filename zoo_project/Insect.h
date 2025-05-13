#pragma once
#include "Animal.h"
class Insect : public Animal
{
private:
	int _numOflegs;
public:
	Insect();
	~Insect();
	void print()const;
	void makeNose()const;
};

