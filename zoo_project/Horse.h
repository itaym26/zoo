#pragma once
#include "Mammel.h"
class Horse : public Mammel
{
private:
	int _speed;
public:
	Horse();
	virtual~Horse();
	virtual void print()const;
	virtual void makeNoise()const;
};

