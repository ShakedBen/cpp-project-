#pragma once
using namespace std;
#include<iostream>
#include"Cats.h"
#include"Fish.h"
class Otariinae:public Cats,public Fish
{
private:
	float finLength;
public:
	/*constructor*/
	Otariinae(const char* name, const float age, const int chamber, const int speedAbility, const int jumpAbility,const int hourSleep,const char * color,const float size,const float swimmingSpeed,const float finLength);
	Otariinae(const char* name, const float age, const int chamber, const Cats& cat, const Fish& fish, const float finLength);
	Otariinae(Cats&& cat,Fish&& fish, float finLength)noexcept;//mc-c'tor
	Otariinae(const Otariinae& other);//c-c'tor
	Otariinae(Otariinae&& other)noexcept;//m-c'tor
		/*operator*/
	const Otariinae& operator=(const Otariinae& other);
	const Otariinae& operator=(Otariinae&& other)noexcept;
			/*set*/
	bool setFinLength(float finLength);
			/*get*/

	float GetFinLength();

		/*method*/
	void show()const;
};

