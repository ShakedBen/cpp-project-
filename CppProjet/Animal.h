#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
using namespace std;

class Animal
{
protected:
	char *name;
	float age;
	int chamber;

public:

	/*constructor*/
	Animal(const char* name,const float age, const int chamber);//c'tor
	Animal(const Animal& other);//c-c'tor
	Animal(Animal&& other)noexcept;//m-c'tor
	virtual ~Animal();
	
		/*operator*/
	const Animal& operator=(const Animal& other);
	const Animal& operator=( Animal&& other)noexcept;

			/*set*/
	bool setName(const char* name);
	bool setAge(const float age);
	bool setChamber(const int chamber);
				/*get*/
	const char* getName();
	const float getAge();
	const int getChamber();

			/*method*/
	 void show() const;

};

