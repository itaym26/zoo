#pragma once
#include "Animal.h"
#include "Mammel.h"
#include "Insect.h"
#include "Lion.h"
#include"Horse.h"
#include "Fly.h"
#include "Zoo.h"

class Zoo
{
private:
	string _name;
	Animal** _arr;
	int _size;
public:
	Zoo(string n);
	~Zoo();
	void printAllAnimal()const;
	void animalParty()const;
	void sortAnimalByName();
	void addAnimal();
	void removeAnimalByName();
	int findAnimalByName()const;
	void MENU();
};

