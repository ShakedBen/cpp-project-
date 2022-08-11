#pragma once
using namespace std;
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include"Register.h"
#include"Zoo.h"
class Login
{
private:
	string name;
	string lastName;
	string phone;
	int ID;
	string email;
	string password;
	string vpassword;
	bool admin;
	bool login;
public:
	Login(string password, string email);
	string decryptPassword(string password);
	bool checkEmailAndPassword(const  string email, const string password);
	void showInfo();
	bool setName(const string name);
	bool setLastName(const string Lastname);
	bool setPhone(const string phone);
	bool setID(const int ID);
	bool setEmail(const string email);
	bool setPassword(const string password, const string vpassword, const string vpassword2 );
	bool isLogin();

	bool equalPassword(const string password, const string vpassword);

	bool nameWithOnlyChar(const string name);
	bool lastNameWithOnlyChar(const string lastName);
	bool checkPhone(const string phone);
	bool uniqueAndValidID(const int ID);
	bool validEmail(const string email);
	bool isChar(char c);
};

