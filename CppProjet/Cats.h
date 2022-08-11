#pragma once
#include "Animal.h"
class Cats:virtual public Animal
{
protected:
	int speedAbility;
	int jumpAbility;
	int hourSleep;
public:

	/*constructor*/
	Cats();
	Cats(const char* name, const float age, const int chamber	, const int speedAbility, const int jumpAbility, const int hourSleep);//c'tor
	Cats(Animal&& base, int speedAbility, int jumpAbility, int hourSleep)noexcept;//mc-c'tor
	Cats(const Cats& other);//c-c'tor
	Cats(Cats&& other)noexcept;//m-c'tor

	/*operator*/
	const Cats& operator=(const Cats& other);
	const Cats& operator=(Cats&& other)noexcept;

	/*set*/
	bool setSpeedAbility(const int speedAbility);
	bool setJumpAbility(const int jumpAbility);
	bool setHourSleep(const int hourSleep);
	/*get*/
	const int getSpeedAbility();
	const int getJumpAbility();
	const int getHourSleep();

	/*method*/
	 void show() const;



};

