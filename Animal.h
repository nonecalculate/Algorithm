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
		cout << "���� ¢�� �Ҹ��� �鸳�ϴ�." << endl << "Woof!" << endl;
	}
};

class Cat : public Animal {

public:
	virtual void makeSound() {
		cout << "����̰� ��µ� �մϴ�." << endl << "Meow!" << endl;
	}

};

class Cow : public Animal {

public:
	virtual void makeSound() {
		cout << "�Ұ� ����ֽ��ϴ�." << endl << "Moo!" << endl;
	}

};
