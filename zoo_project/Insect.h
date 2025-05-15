#pragma once
#include "Animal.h"
class Insect : public Animal
{
private:
	int _numOflegs;
public:
	Insect();
	virtual~Insect();
	virtual void print()const;
	virtual void makeNose()const;
};

