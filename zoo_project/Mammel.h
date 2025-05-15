#pragma once
#include "Animal.h"
class Mammel : public Animal
{
private:
	bool _gotMilk;
public:
	Mammel();
	virtual~Mammel();
	virtual void print()const;
	virtual void makeNoise()const;
};
 
