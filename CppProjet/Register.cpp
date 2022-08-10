#include "Register.h"
#include <string>
#include <fstream>
Register::Register(string name,
	string lastName,
	string phone,
	int ID,
	string email,
	string password,
	string vpassword,
	bool admin=false)
{
	bool a, b, c, d, e, f,g,h;
	a = nameWithOnlyChar(name);
	if (a == false)
	{
		return;
	}
	b = lastNameWithOnlyChar(lastName);
	if (b == false)
	{
		return;
	}
	c = checkPhone(phone);
	if (c == false)
	{
		return;
	}
	d = uniqueAndValidID(ID);
	if (d == false)
	{
		return;
	}
	e = uniqueEmail(email);
	if (e == false)
	{
		return;
	}
	f = strongPassword(password);
	if (f == false)
	{
		return;
	}
	g = equalPassword(password, vpassword);
	h = validEmail(email);
	if (a == true&& b == true&& c == true&& d == true &&e == true&&f == true&& g == true&&h==true)
	{
		ofstream outFile("users.txt", ios::app);
		outFile << name<<endl;
		outFile << lastName << endl;
		outFile << phone << endl;
		outFile << email << endl;
		outFile << ID << endl;
		outFile << this->password << endl;
		outFile << admin << endl;
		outFile.close();
		cout << "The registration was successful" << endl;
	}
}
bool Register::checkPhone(const string phone)
{
	if (int(phone.length()) == 10)
	{
		for (int i = 0; i<int(phone.length()); i++)
		{
			if (phone[i] >= '0' && phone[i] <= '9')
			{
				continue;
			}
			else {
				cout << "A phone number should only contain digits" << endl;
				return false;
			}
		}
		this->phone = phone;
		return true;
	}
}
	bool Register::uniqueEmail(const string email)
	{
		string name, lastName, phone, email1, password;
		int id;
		bool admin;
		ifstream inFile("users.txt");
		while (!inFile.eof())
		{
			inFile >> name >> lastName >> phone >>  email1>> id >> password >> admin;
			if (email1 == email)
			{
				cout << "this email already exists in the system" << endl;
				inFile.close();
				return false;
			}
		}
		inFile.close();
		this->email = email;
		return true;
	}

	bool Register::uniqueAndValidID(const int ID)
	{
		string name, lastName, phone, email, password;
		int id;
		bool admin;
		int counter=0,sum=0,j=1,y=1;
		bool flag = false;
		ifstream inFile("users.txt");
		while(!inFile.eof())
		{
			inFile >> name >> lastName >> phone ;
			inFile >> email >>id >> password >> admin;
			if (id == ID)
			{
				cout << "this ID already exists in the system" << endl;
				inFile.close();
				return false;
			}
		}
		inFile.close();
		for (int i = 0; ID / j != 0; i++)
		{
			sum += (ID / j % 10) * ((i % 2) + 1);
			j *= 10;
			counter++;
		}
		if (counter!=9)
		{
			cout << "There is an error in the ID number" << endl;
			return false;
		}
		if ((sum + (ID % 10)) % 10 == 0)
		{
			this->ID = ID;
			return true;
		}

	}

	bool Register::strongPassword(const string password) {
		bool flag = true;
		bool asciiSign = false, lowLetter = false, highLetter = false, number = false;
		if (password.length() < 6)
		{
			cout << "The password is too short" << endl;
			return false;
		}
		for (int i = 0; i < int(password.length()); i++)
		{
			if ((password[i] > 32 && password[i] < 48)||(password[i]>57&& password[i]<65)||(password[i]>90&& password[i]<97)||(password[i]>122&& password[i]<127))
			{
				asciiSign = true;
				continue;
			}
			if (password[i] > 47 && password[i] < 58)
			{
				number = true;
				continue;
			}
			if (password[i] > 65 && password[i] < 91)
			{
				highLetter = true;
				continue;
			}
			if (password[i] > 96 && password[i] < 123)
			{
				lowLetter = true;
			}
		}
		if (flag == true && asciiSign == true && number == true && highLetter == true && lowLetter == true)
		{
			this->password = encryptPassword(password);
			//this->password = decryptPassword(this->password);
			return true;
		}
		else
		{
			cout << "The password is too weak" << endl;
			return false;
		}
	}
	bool Register::nameWithOnlyChar(const string name) {
		for (int i = 0; i < int(name.length()); i++)
		{
			if ((name[i] > 65 && name[i] < 91) || (name[i] > 96 && name[i] < 123))
			{
				this->name = name;
				return true;
			}
			else {
				cout << "The name should contain only letters" << endl;
				return false;
			}
		}
	
	
	}
	bool Register::lastNameWithOnlyChar(const string lastName){
		for (int i = 0; i < int(lastName.length()); i++)
		{
			if ((lastName[i] > 65 && lastName[i] < 91) || (lastName[i] > 96 && lastName[i] < 123)||(lastName[i]=='-'|| lastName[i]==' '))
			{
				this->lastName = lastName;
				return true;
			}
			else {
				cout << "The name should contain only letters" << endl;
				return false;
			}
		}
	}
	bool Register::equalPassword(const  string password, const  string vpassword) {
		if (password.length() != vpassword.length())
		{
			cout << "The passwords should be the same length" << endl;
			return false;
		}
		for (int i = 0; i < int(password.length()); i++)
		{
			if (password[i] != vpassword[i])
			{
				cout << "The passwords should be the same" << endl;
				return false;
			}
		}
		return true;
	}
	string Register::encryptPassword(string password) {
		int sign=-1,key=3,key2=2;
		string passwordEncryption=password;
		for (int i = 0; i<int(password.length()); i++)
		{
			key =  (key*sign*key2)/2;//-3
			passwordEncryption[i] = passwordEncryption[i] + key;
			key2++;
		}

		return passwordEncryption;


	}
	bool Register::isChar(char c)
	{
		return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
	}
	bool Register::validEmail(const string email) {
		// Check the first character
		// is an alphabet or not
		if (!isChar(email[0])) {

			// If it's not an alphabet
			// email id is not valid
			cout << "There is a problem with the format of the email"<<endl;
			return false;
		}
		// Variable to store position
		// of At and Dot
		int At = -1, Dot = -1;

		// Traverse over the email id
		// string to find position of
		// Dot and At
		for (int i = 0;
			i < email.length(); i++) {

			// If the character is '@'
			if (email[i] == '@') {

				At = i;
			}

			// If character is '.'
			else if (email[i] == '.') {

				Dot = i;
			}
		}

		// If At or Dot is not present
		if (At == -1 || Dot == -1)
		{
			cout << "There is a problem with the format of the email" << endl;
			return false;
		}
		// If Dot is present before At
			if (At > Dot)
			{
				cout << "There is a problem with the format of the email" << endl;
				return false;
			}
		// If Dot is present at the end
		if (Dot >= (email.length() - 1))
		{
			cout << "There is a problem with the format of the email" << endl;
			return false;
		 }
		return true;
	}
