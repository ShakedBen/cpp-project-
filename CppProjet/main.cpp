using namespace std;
#include<iostream>
#include <fstream>
#include"Register.h"
#include"Login.h"
#include <conio.h>

int main()
{

	string name = "shaked";
	string lastName = "ben-hamo";
	string phone = "0505500891";
	int ID = 204713952;
	string email = "shaked@gmail.com";
	string password = "Ss1@#Ss12";
	string vpassword = "Ss1@#Ss12";
	string vpassword2;
	Register* acc;
	Login* accLog=NULL;
	bool run = true;
	int pick;
	int ch;
	while (run)
	{
		cout << "**************************" << endl;
		cout << "*  Wellcome to the menu  *" << endl;
		cout << "*To connect press      1 *" << endl;
		cout << "*To register click     2 *" << endl;
		cout << "*To edit profile click 3 *" << endl;
		cout << "*To exit click         0 *" << endl;
		cout << "**************************" << endl;
	cin >> pick;
		switch (pick)
		{
		case 1: {
			cout << "Login Page" << endl;
			/*
			cout << "Enter Username: ";
			cin >> email;
			cout << "Enter password: ";
		
				ch = _getch();
				while (ch != 18)
				{
				password.push_back(ch);
				cout << 'x';
				ch = _getch();
			}
			*/
			//cin >> password;
			accLog = new Login(email, password);
		}

			  break;
		case 2:
		{
			/*
			cout << "Register Page" << endl;

			cout << "Enter name: ";
			cin >> name;

			cout << "Enter last name: ";
			cin >> lastName;
			cout << "Enter phone number with 10 digits: ";
			cin >> phone;

			cout << "Enter ID number: ";
			cin >> ID;

			cout << "Enter Email (username): ";
			cin >> email;

			cout << "Enter password with upper and lower case letters numbers and sign: ";
			cin >> password;

			cout << "Enter password again: ";
			cin >> vpassword;
			*/
			acc = new Register(name, lastName, phone, ID, email, password, vpassword, false);
		}
		break;
		case 3:
		{
		
			if (accLog->isLogin())
			{
				accLog->showInfo();
				int pick2;
				bool run2 = true;
				cout << "******************************************" << endl;
				cout << "*To edit name click                    1 *" << endl;
				cout << "*To edit last name click               2 *" << endl;
				cout << "*To edit phone click                   3 *" << endl;
				cout << "*To edit ID click                      4 *" << endl;
				cout << "*To edit email click                   5 *" << endl;
				cout << "*To edit password click                6 *" << endl;
				cout << "*To return to the previous page click  0 *" << endl;
				cout << "******************************************" << endl;
				cin >> pick2;
				while (run2)
				{

					switch (pick2)
					{
					case 1: {
						cout << "Enter new Name :" << endl;
						cin >> name;
						accLog->setName(name);
						pick2 = 0;
					
					}	break;
					case 2: {
						cout << "Enter new Last-Name :" << endl;
						cin >> lastName;
						accLog->setLastName(lastName);
						pick2 = 0;
					}break;
					case 3: {
						cout << "Enter new Phone :" << endl;
						cin >> phone;
						accLog->setPhone(phone);
						pick2 = 0;
					}break;
					case 4: {
						cout << "Enter new ID :" << endl;
						cin >> ID;
						accLog->setID(ID); 
						pick2 = 0;
					}break;
					case 5: {
						cout << "Enter new Email :" << endl;
						cin >> email;
						accLog->setEmail(email); 
						pick2 = 0;
					}break;
					case 6: {
						//cout << "Enter your Password :";
							//cin >> password;
							password = "Ss1@#Ss12";
							//cout << "Enter your new Password :";
							//cin >> vpassword;
							vpassword = "!23AsDer";
							//cout << "Enter your new Password again :";
							//cin >> vpassword2;
							vpassword2 = "!23AsDer";
							accLog->setPassword(password, vpassword, vpassword2);
							pick2 = 0;
					
					}break;
					default: {
						if (pick2 == 0)
						{
							run2 = false;
							cout << "Your profile :" << endl;
							accLog->showInfo();
							pick2 = 0;
						}
						else
						{
							cout << "try to pick number between 1 to 6" << endl << endl;
						}
						break;
					}break;

					}

				}
			}
			else

			{
				cout << "Please try to login before you can access the profile" << endl<<endl;
			}
		}
		break;
		default: 
			if (pick == 0)
			{
				run = false;
				cout << "Goodbey" << endl;
			}
			else
			{
				cout << "try to pick number between 1 to 3" << endl << endl;
			}
			break;
		}

	}
	}


