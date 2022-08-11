#include "Otariinae.h"
Otariinae::Otariinae(const char* name, const float age, const int chamber, const int speedAbility, const int jumpAbility, const int hourSleep, const char* color, const float size, const float swimmingSpeed, const float finLength)
	:Animal(name, age, chamber), Cats(name, age, chamber,speedAbility, jumpAbility, hourSleep), Fish(name, age, chamber,color, size, swimmingSpeed), finLength(finLength){}


Otariinae::Otariinae(const char* name, const float age, const int chamber,const Cats &cat, const Fish& fish, const float finLength)
	:Animal(name,age,chamber),Cats(cat),Fish(fish), finLength(finLength){}

Otariinae::Otariinae(Cats&& cat, Fish&& fish, float finLength)noexcept:Animal(std::move(cat.getName()), std::move(cat.getAge()), std::move(cat.getChamber())),Cats(std::move(cat)),Fish(std::move(fish)),finLength(std::move(finLength))//mc-c'tor
{}
Otariinae::Otariinae(const Otariinae& other)//c-c'tor
{
	*this = other;
}
Otariinae::Otariinae(Otariinae&& other)noexcept//m-c'tor
{
	*this = (std::move(other));
}
	/*operator*/
const Otariinae& Otariinae:: operator=(const Otariinae& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		Cats::operator=(other);
		Fish::operator=(other);
		this->finLength = finLength;

	}
	return *this;
}
const Otariinae& Otariinae::operator=(Otariinae&& other)noexcept
{
	if (this != &other)
	{
		Animal::operator=(std::move(other));
		Cats::operator=(std::move(other));
		Fish::operator=(std::move(other));
		swap(this->finLength , finLength);

	}
	return *this;
}
/*set*/
bool Otariinae::setFinLength(float finLength)
{
	if (finLength < 0)
	{
		cout << "Fin length cannot be less than 0" << endl;
		return false;
	}
	this->finLength = finLength;
	return true;
}
/*get*/

float Otariinae::GetFinLength()
{
	return this->finLength;
}

/*method*/
void Otariinae::show()const
{
	Cats::show();
	Fish::show();
	cout << "fin length is :" << finLength << endl;

}