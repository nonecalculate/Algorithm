#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Animal.h"
#include"Zoo.h"
using namespace std;
Animal* createRadnomAnimal() {
	int num = rand() % 3;
	if (num == 0)return new Dog;
	else if (num == 1)return new Cow;
	else if (num == 2)return new Cat;
	else return 0;

}

int main() {
	srand((unsigned int)time(NULL));
	Zoo zoo;
	Animal* pets[10] = { nullptr };
	for (int i = 0; i < 10; i++) {
		if(pets[i] == nullptr) pets[i] = createRadnomAnimal();
		zoo.addAnimal(pets[i],i);
	}
	zoo.performActions();
	for (int i = 0; i < 10; i++) {
		pets[i] = nullptr; 
	}
	return 0;
}
