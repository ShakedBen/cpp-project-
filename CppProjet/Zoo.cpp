#include "Zoo.h"
Zoo::Zoo()
{
	ListOfAnimal = NULL;
	sizeOfAnimal = 0;
}
void Zoo::operator+=(Animal* animal)
{
	Animal** temp;
	temp = new Animal * [sizeOfAnimal + 1];
	for (int i = 0; i < sizeOfAnimal; i++)
	{
		temp[i] = ListOfAnimal[i];
	}
	temp[sizeOfAnimal] = animal;
	sizeOfAnimal++;
	if (ListOfAnimal)
		delete[]ListOfAnimal;
	ListOfAnimal = temp;
}
Zoo::~Zoo()
{
	for (int i = 0; i < sizeOfAnimal; i++)
	{
		delete ListOfAnimal[i];
	}
	delete[]ListOfAnimal;
}
bool  Zoo::onlyChar(char* str)
{
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			continue;
		}
		else
		{
			cout << "Does not contain only letters" << endl;
			return false;
		}
	}
	return true;
}
void Zoo::Start()
{
	Animal* animal = NULL;
	char name[20],  color[20];
	float age;
	int chamber=0;
	int speedAbility, jumpAbility, hourSleep;
	float size,swimmingSpeed,finLength;
	cout << "******************************" << endl;
	cout << "*Hello and welcome to the zoo*" << endl;
	cout << "******************************" << endl;
	cout << endl;
	cout << endl;
	bool run = true,onlystr=false;

	int amountOfAnimals, pick;
	cout << "Select the amount of animals" << endl;
	cin >> amountOfAnimals;
	while (run)
	{
		cout << "****************************" << endl;
		cout << "* To add Cat click       1 *" << endl;
		cout << "* To add Fish click      2 *" << endl;
		cout << "* To add Qtariinae click 3 *" << endl;
		cout << "* To Exit click          0 *" << endl;
		cout << "****************************" << endl;
		cin >> pick;
		switch (pick) 
		{
		case 1: {
			while (!onlystr)
			{
				cout << "Enter name: ";
				cin >> name;
				onlystr = onlyChar(name);
			}
			cout << "Enter age: ";
			cin >> age;
			chamber++;
			cout << "Enter speed ability: ";
			cin >> speedAbility;
			cout << "Enter jump ability: ";
			cin >> jumpAbility;
			cout << "Enter hour sleep: ";
			cin >> hourSleep;
			animal = new Cats(name, age, chamber, speedAbility, jumpAbility, hourSleep);
			onlystr = false;
		}break;
		case 2: {
			while (!onlystr)
			{
				cout << "Enter name: ";
				cin >> name;
				onlystr = onlyChar(color);
			}
			cout << "Enter age: ";
			cin >> age;
			chamber++;
			while (!onlystr)
			{
				cout << "Enter color of fish :";
				cin >> color;
				onlystr = onlyChar(name);
			}
			cout << "Enter size of fish: ";
			cin >> size;
			cout << "Enter swimming Speed :";
			cin >> swimmingSpeed;
			onlystr = false;
			animal = new Fish(name, age, chamber,color, size, swimmingSpeed);
		}break;
		case 3: {
			while (!onlystr)
			{
				cout << "Enter name: ";
				cin >> name;
				onlystr = onlyChar(name);
			}
			cout << "Enter age: ";
			cin >> age;
			chamber++;
			cout << "Enter speed ability: ";
			cin >> speedAbility;
			cout << "Enter jump ability: ";
			cin >> jumpAbility;
			cout << "Enter hour sleep: ";
			cin >> hourSleep;
			while (!onlystr)
			{
				cout << "Enter color of fish :";
				cin >> color;
				onlystr = onlyChar(name);
			}
			cout << "Enter size of fish: ";
			cin >> size;
			cout << "Enter swimming Speed :";
			cin >> swimmingSpeed;
			cout << " Enter fin Length :";
			cin >> finLength;
			onlystr = false;
			animal = new Otariinae(name, age, chamber, speedAbility, jumpAbility, hourSleep, color, size, swimmingSpeed, finLength);
		
		}break;
		default: {
			if (pick == 0)
			{
				run = false;
		}
			else {
				cout << "Try to enter a number between 1-3" << endl;
			}
		}break;
		}
		operator+=(animal);
	}
}
