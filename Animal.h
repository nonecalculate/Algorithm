#pragma once
#include<iostream>

using namespace std;
class Animal {
public:
	virtual void makeSound() = 0;
	
	~Animal() {  };
};

class Dog : public Animal {

public:
	virtual void makeSound() {
		cout << "개가 짖는 소리가 들립니다." << endl << "Woof!" << endl;
	}
};

class Cat : public Animal {

public:
	virtual void makeSound() {
		cout << "고양이가 우는듯 합니다." << endl << "Meow!" << endl;
	}

};

class Cow : public Animal {

public:
	virtual void makeSound() {
		cout << "소가 울고있습니다." << endl << "Moo!" << endl;
	}

};
