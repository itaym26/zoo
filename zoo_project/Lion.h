#pragma once
#include "Mammel.h"
class Lion : public Mammel
{
private:
	int _volume;
public:
	Lion();
	virtual~Lion();
	virtual void print()const;
	virtual void makeNoise()const;
};

