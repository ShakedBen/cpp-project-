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
	Otariinae(const char* name, const float age, const int chamber, const Cats& cat, const Fish& fish, const float finLength);

			/*set*/
	bool setFinLength(float finLength);
			/*get*/

	float GetFinLength();

		/*method*/
	void show()const;
};

