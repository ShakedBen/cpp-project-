#pragma once
using namespace std;
#include<iostream>
class Register
{
private:
	//static int usersDBsize;
	string name;
	string lastName;
	string phone;
	int ID;
	string email;
	string password;
	string vpassword;
	bool admin;
public:
	Register(string name,
			string lastName,
			string phone,
			int ID,
			string email,
			string password,
			string vpassword,
			bool admin );


			/*method*/
	bool uniqueEmail(const string email);
	bool uniqueAndValidID(const int ID);
	bool strongPassword(const string password);
	bool nameWithOnlyChar(const string name);
	bool checkPhone(const string phone);
	bool lastNameWithOnlyChar(const string lastName);
	bool equalPassword(const string password, const string vpassword);
	bool validEmail(const string email);
	bool isChar(char c);
	string encryptPassword(string password);

};

