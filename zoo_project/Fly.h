#pragma once
#include "Insect.h"
class Fly : public Insect
{
private:
	int _lifeTime;
public:
	Fly();
	virtual~Fly();
	virtual void print()const;
	virtual void makeNoise()const;
};

