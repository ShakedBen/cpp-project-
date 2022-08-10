#include "Otariinae.h"
Otariinae::Otariinae(const char* name, const float age, const int chamber,const Cats &cat, const Fish& fish, const float finLength)
	:Animal(name,age,chamber),Cats(cat),Fish(fish), finLength(finLength){}