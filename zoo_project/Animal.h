#pragma once
#include<iostream>
#include<string>
using namespace std;
class Animal
{
protected:
	int _animalType;
private:
	string _animalName;
	int _animalAge;
public:
	Animal();
	virtual ~Animal();
	virtual void print()const;
	virtual void makeNoise()const;
	string getName()const { return this->_animalName;}
};
