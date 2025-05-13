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
	~Animal();
	void print()const;
	void makeNoise()const;

};
