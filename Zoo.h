#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Animal.h"

class Zoo {
private:
	Animal* animals[10] = { nullptr };
public:

	void addAnimal(Animal* animal, int j) {
		if(animals[j] == nullptr) animals[j] = animal;
	}
	
	void performActions() {
		for (int i = 0; i < 10; i++) {
			if (animals[i] != nullptr) animals[i] -> makeSound();
		}
	}

	~Zoo() {
		cout << endl << "Zoo �Ҹ��� �θ�";
		for (int i = 0; i < 10; i++) {
			if (animals[i] != nullptr) {
				delete animals[i];
				animals[i] = nullptr;
			}
		}
	}
};