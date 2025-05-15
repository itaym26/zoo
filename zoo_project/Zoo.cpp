
#include "Zoo.h"
#include <string>

Zoo::Zoo(string n) :_arr(NULL), _size(0), _name(n) { cout << "Zoo constructed..." << endl; }
Zoo::~Zoo() {
	for (int i = 0; i < this->_size; i++)
		delete this->_arr[i];
	delete[] this->_arr;
	cout << "Zoo deleted..."<<endl;
}
void Zoo::printAllAnimal()const {
	cout << "Zoo's name:" << this->_name << endl;
	if (this->_size == 0) {
		cout << "Empty zoo" << endl;
		return;
	}
	cout << "The size of zoo:" << this->_size << endl;
	for (int i=0; i < this->_size; i++) {
		cout << "******************************" << endl;
		cout << "Animal number:" << i + 1 << ":" << endl;
		this->_arr[i]->print();
	}
	cout << "******************************" << endl;
}
void Zoo::animalParty()const {
	cout << "Zoo's name:" << this->_name << endl;
	if (this->_size == 0) {
		cout << "Empty zoo" << endl;
		return;
	}
	cout << "The size of zoo:" << this->_size << endl;
	for (int i=0; i < this->_size; i++) {
		cout << "******************************" << endl;
		this->_arr[i]->makeNoise();
	}
	cout << "******************************" << endl;
}
void Zoo::sortAnimalByName() {
	int i, j;
	Animal* temp;
	for (i = 0; i < this->_size; i++) {
		for (j = 0; j < this->_size-i-1; j++) {
			if (this->_arr[j]->getName() > this->_arr[j + 1]->getName()) {
				temp = this->_arr[j];
				this->_arr[j] = this->_arr[j + 1];
				this->_arr[j + 1] = temp;
			}
		}
	}
	cout << "Zoo sorted..." << endl;
}
int Zoo::findAnimalByName()const{
	cout<<"Enter the name of the animal:";
	string t;
	cin >> t;
	for (int i = 0; i < this->_size; i++) {
		if (this->_arr[i]->getName() == t)
			return i;
		return -1;
	}
}
void Zoo::addAnimal() {
	Animal** newArr = new Animal * [this->_size + 1];
	for (int i = 0; i < this->_size; i++)
		newArr[i] = this->_arr[i];

	delete[] this->_arr;
	this->_arr = newArr;
	this->_size++;

	cout << "Which animal type do you want to add?" << endl;
	cout << "Sub menu:" << endl;
	cout << "********************" << endl;
	cout << "0) Regular animal" << endl;
	cout << "1) Mammal" << endl;
	cout << "2) Insect" << endl;
	cout << "3) Lion" << endl;
	cout << "4) Horse" << endl;
	cout << "5) Fly" << endl;

	int choice;
	cout << "Your choice: ";
	cin >> choice;

	switch (choice) {
	case 0:
		this->_arr[this->_size - 1] = new Animal();
		break;
	case 1:
		this->_arr[this->_size - 1] = new Mammel();
		break;
	case 2:
		this->_arr[this->_size - 1] = new Insect();
		break;
	case 3:
		this->_arr[this->_size - 1] = new Lion();
		break;
	case 4:
		this->_arr[this->_size - 1] = new Horse();
		break;
	case 5:
		this->_arr[this->_size - 1] = new Fly();
		break;
	default:
		cout << "Invalid choice. Adding regular animal by default." << endl;
		this->_arr[this->_size - 1] = new Animal();
	}

	cout << "Animal added..." << endl;
}

void Zoo::removeAnimalByName() {
	int index= this->findAnimalByName();
	if (index== -1) {
		cout << "The animal not exists" << endl;
		return;
	}
	delete this->_arr[index];
	this->_arr[index] = this->_arr[this->_size - 1];
	Animal** temp = new Animal * [this->_size - 1];
	for (int i = 0; i < this->_size - 1; i++) 
		temp[i] = this->_arr[i];
	delete[]this->_arr;
	this->_size--;
	this->_arr = temp;
	cout << "Animal deleted..." << endl; 
}
void Zoo::MENU() {
	int choice;
	while (1)
	{
		cout << "Main menu:" << endl;
		cout << "*******************" << endl;
		cout << "1)Print all animals" << endl;
		cout << "2)Animals party" << endl;
		cout << "3)Sort all animals by name" << endl;
		cout << "4)Find animal by name" << endl;
		cout << "5)Add an animal" << endl;
		cout << "6)Remove animal by name" << endl;
		cout << "7) EXIT" << endl;
		cout << "Your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1: this->printAllAnimal();
			break;
		case 2:this->animalParty();
			break;
		case 3:this->sortAnimalByName();
			break;
		case 4: {
			int index = this->findAnimalByName();
			if (index == -1)cout << "Not found" << endl;
			else cout << "Found at index:" << index << endl;
			break;
		}
		case 5:this->addAnimal();
			break;
		case 6:this->removeAnimalByName();
			break;
		case 7: cout << "Godd bye" << endl;
			return;
		default:
			cout << "Wrong choice,Please try again" << endl;
		}

	}
}