#include "Animal.h"
/*constructor*/
Animal::Animal(const char* name, const float age, const int chamber):name(NULL)//c'tor
{
	if(this->name==NULL)
		delete[]this->name;
	this->name = _strdup(name);
	this->age = age;
	this->chamber = chamber;

}
Animal::Animal(const Animal& other) :name(NULL)//c-c'tor
{
	*this = other;
}
Animal::Animal(Animal&& other)noexcept//m-c'tor
{
	*this = (std::move(other));
}
Animal:: ~Animal()//d'tor
{
	delete[]name;
}

/*operator*/
const Animal& Animal:: operator=(const Animal& other)
{
	
	if (this != &other)
	{
		delete[]this->name;
		this->name = _strdup(other.name);
		this->age = other.age;
		this->chamber = other.chamber;
	}
	return *this;
}
const Animal& Animal::operator=(Animal&& other)noexcept
{
	if (this != &other) {
		swap(name, this->name);
		this->age = other.age;
		this->chamber = other.chamber;
	}
	return *this;
}

/*set*/
bool Animal::setName(const char* name)
{
	if (name != NULL)
	{
		delete[]this->name;
		this->name = _strdup(name);
		return true;
	}
	return false;
}
bool Animal::setAge(const float age)
{
	this->age = age;
	return true;

}
bool Animal::setChamber(const int chamber)
{
	this->chamber = chamber;
	return true;
}
/*get*/
const char* Animal:: getName()
{
	return name;
}
const float Animal::getAge()
{
	return age;
}
const int Animal::getChamber()
{
	return chamber;
}

void Animal::show() const
{
}

/*method*/
void Animal::show() const {
	cout << "name is: " << name << " age is: " << age << " chamber is :" << chamber << endl;
