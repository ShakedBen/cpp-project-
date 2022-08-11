#pragma once
#include "Otariinae.h"
#include<iostream>
using namespace std;
class Zoo
{
private:
	Animal** ListOfAnimal;
	int sizeOfAnimal;
public:
	Zoo();
	~Zoo();
	void operator+=(Animal* animal);
	void Start();
	bool onlyChar(char *str);
};