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
	void makeNoise() const override;
	virtual void makeNose() const; // Legacy spelling retained for compatibility.
};
