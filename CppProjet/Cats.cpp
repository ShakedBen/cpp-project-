#include "Cats.h"
/*constructor*/
Cats::Cats(const char* name, const float age, const int chamber, const int speedAbility, const int jumpAbility, const int hourSleep):Animal(name,age,chamber), speedAbility(speedAbility), jumpAbility(jumpAbility), hourSleep(hourSleep)//c'tor
{}
Cats::Cats(Animal&& base, int speedAbility, int jumpAbility, int hourSleep)noexcept :Animal(std::move(base)), speedAbility(speedAbility), jumpAbility(jumpAbility), hourSleep(hourSleep)//mc-c'tor
{}
Cats::Cats(const Cats& other)//c-c'tor
{
	*this = other;
}
Cats::Cats(Cats&& other)noexcept//m-c'tor
{
	*this = std::move(other);
}
/*operator*/
const Cats& Cats::operator=(const Cats& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->speedAbility = other.speedAbility;
		this->jumpAbility = other.jumpAbility;
		this->hourSleep = other.hourSleep;
	}
	}
const Cats& Cats::operator=(Cats&& other)noexcept
{
	if (this != &other)
	{
		Animal::operator=(std::move(other));
		std::swap(this->speedAbility  ,other.speedAbility);
		std::swap(this->jumpAbility , other.jumpAbility);
		std::swap(this->hourSleep , other.hourSleep);
	}
}

/*set*/
bool Cats::setSpeedAbility(const int speedAbility)
{
	if (speedAbility > 0)
	{
		this->speedAbility = speedAbility;
		return true;
	}
	cout << "Cat speed ability need to be more then 0 " << endl;
	return false;
}
bool Cats::setJumpAbility(const int jumpAbility)
{
	if (jumpAbility > 0)
	{
		this->jumpAbility = jumpAbility;
		return true;
	}
	cout << "Cat jump ability need to be more then 0 " << endl;
	return false;

}
bool Cats::setHourSleep(const int hourSleep)
{
	if (hourSleep > 0&& hourSleep<24)
	{
		this->hourSleep = hourSleep;
		return true;
	}
	cout << "Cat need to sleep more then 0 hours and less then 24 hours" << endl;
	return false;

}
/*get*/
const int Cats::getSpeedAbility()
{
	return speedAbility;
}
const int Cats::getJumpAbility()
{
	return jumpAbility;
}
const int Cats::getHourSleep()
{
	return hourSleep;
}

/*method*/
void Cats::show() const
{
	Animal::show();
	cout << "Speed ability :" << speedAbility << " Jump ability :" << jumpAbility << " Sleeping hours :" << hourSleep;
}