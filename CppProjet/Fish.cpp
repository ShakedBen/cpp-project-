#include "Fish.h"
#include<string>
#define _CRT_SECURE_NO_WARNINGS
/*constructor*/
Fish::Fish()
{
	color = NULL;
	size = 0;
	swimmingSpeed = 0;
}
Fish::Fish(const char* name, const float age, const int chamber, const char* color, const float size, const float swimmingSpeed) :Animal(name, age, chamber)//c'tor
{
	if (this->color == NULL)
		delete[]this->color;
	this->color = _strdup(color);
	this->size = size;
	this->swimmingSpeed = swimmingSpeed;
}
Fish::Fish(Animal&& base, char* color, float size, float swimmingSpeed)noexcept :Animal(std::move(base)),color(NULL)//mc-c'tor
{
	this->color = _strdup(color);
	this->size = size;
	this->swimmingSpeed = swimmingSpeed;
}
Fish::Fish(const Fish& other)//c-c'tor
{
	*this = other;
}
Fish::Fish(Fish&& other)noexcept//m-c'tor
{
	*this = std::move(other);
}
/*operator*/
const Fish& Fish::operator=(const Fish& other)
{
	if (this!= &other)
	{
		Animal::operator=(other);
		this->color = _strdup(other.color);
		this->size = other.size;
		this->swimmingSpeed = other.swimmingSpeed;
	}
	return *this;
}
const Fish& Fish:: operator=(Fish&& other)noexcept
{
	if (this != &other)
	{
		Animal::operator=(std::move(other));
		swap(this->color,other.color);
		swap(this->size , other.size);
		swap(this->swimmingSpeed, other.swimmingSpeed);

	}
	return *this;
}
Fish::~Fish()
{
	delete[]this->color;
}

/*set*/
bool Fish::setColor(const char* color)
{
	if (color == NULL||strlen(color)==0)
	{
		cout << "name cant to be empty" << endl;
		return false;

	}
	this->color = _strdup(color);
	return true;
}
bool Fish::setSize(const float size)
{
	if (size <= 0)
	{
		cout << "The size cannot be smaller than 0" << endl;
		return false;
	}
	this->size = size;
	return true;
}
bool Fish::setSwimmingSpeed(const float swimmingSpeed)
{
	if (swimmingSpeed < 0)
	{
		cout << "The swimming speed cannot be less than 0"<<endl;
		return false;
	}

}
/*get*/
const char* Fish::getColor() {
	return this->color;
}
const float Fish::getSize() {
	return this->size;
}
const float Fish::getSwimmingSpeed() {
	return this->swimmingSpeed;
}

/*method*/
void Fish::show() const
{
	Animal::show();
	cout << " color is: " << color << " size is: " << size << " swimming speed is :" << swimmingSpeed << endl;
}