#pragma once
#include "Animal.h"
class Fish :virtual public Animal {
protected:
	char *color;
	float size;
	float swimmingSpeed;

public:

	/*constructor*/
	Fish(const char* name, const float age, const int chamber, const 	char* color,const float size,const float swimmingSpeed);//c'tor
	Fish(Animal&& base, char* color, float size, float swimmingSpeed)noexcept;//mc-c'tor
	Fish(const Fish& other);//c-c'tor
	Fish(Fish&& other)noexcept;//m-c'tor
	virtual ~Fish();
	/*operator*/
	const Fish& operator=(const Fish& other);
	const Fish& operator=(Fish&& other)noexcept;

	/*set*/
	bool setColor(const char*color);
	bool setSize(const float size);
	bool setSwimmingSpeed(const float swimmingSpeed);
	/*get*/
	const char* getColor();
	const float getSize();
	const float getSwimmingSpeed();

	/*method*/
	 void show() const;
};
	


