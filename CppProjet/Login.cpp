#include "Login.h"
Login::Login(string email,string password)
{
	bool a;
	a = checkEmailAndPassword(email, password);
	if (a == true)
	{
		cout<< "Login was successful" << endl;
	}
}

bool Login::checkEmailAndPassword(const string email, const string password)
{
	string name, lastName, phone, email1, password1;
	int id;
	bool admin;
	ifstream inFile("users.txt");
	if (inFile.fail())
	{
		cout << "Error trying to connect to database" << endl;
		return false;
	}
	else
	{
		while (!inFile.eof())
		{
			inFile >> name >> lastName >> phone >> email1 >> id >> password1 >> admin;
			if (email1 == email && decryptPassword(password1) == password)
			{
				this->email = email;
				this->password = password;
				this->name = name;
				this->phone = phone;
				this->ID = id;
				this->admin = admin;
				this->lastName = lastName;
				inFile.close();
				return true;
			}
			else if (email1 == email && decryptPassword(password1) != password)
			{
				inFile.close();
				cout << "The password is incorrect" << endl;
				this->login = false;
				return false;

			}

		}
	}
	inFile.close();
	cout << "This email does not exist in the system yet" << endl;
	this->login = false;
	return false;
}
string Login::decryptPassword(string password)
{
	int sign = -1, key = 3,key2=2;
	string passwordDecryption = password;
	for (int i = 0; i<int(password.length()); i++)
	{
		passwordDecryption[i] = passwordDecryption[i] + key;
		key2++;
		key = (key * key2*sign) / 2;//-3
	
	}

	return passwordDecryption;
}
void Login::showInfo()
{
	cout << "name is: " << name << endl << "last name is: " << lastName << endl << "phone is: " << phone << endl << "ID is: " << ID << endl << "password is: xxxxx" << endl;
}




bool Login::setName(const string name)
{
	
	string fileName = "users.txt";
	string text = name;
	int lineNumber=0,counter=0;
	bool flag = false;
	fstream readFile;
	readFile.open(fileName);
	bool a;

	a=nameWithOnlyChar(name);
	if (a == false)
	{
		cout << "Error The name cannot be changed" << endl;
		return false;
	}
	if (readFile.fail())
	{
		cout << "Error The name cannot be changed" << endl;
		return false;
	}
	vector<string>lines;
	string line;
	while (getline(readFile, line))
	{
		lines.push_back(line);
		counter++;
		if (line == email)
		{
			flag = true;
			lineNumber = counter - 4;
		}
	}
	readFile.close();
	ofstream writeFile;
	writeFile.open(fileName);
	if (writeFile.fail()||flag==false)
	{
		cout << "Error The name cannot be changed" << endl;
		return false;
	}
	if (lineNumber == 0)
	{
		writeFile << text << endl;
		this->name = name;
	}
	for (int i = 0; i < lines.size(); i++)
	{
		if (i != lineNumber)
		{
			writeFile << lines[i] << endl;
		}
		else 
		{
			writeFile << text << endl;
			this->name = name;
		}
	}
	writeFile.close();
	return true;

}
bool Login::setLastName(const string Lastname) {

	string fileName = "users.txt";
	string text = Lastname;
	int lineNumber = 0, counter = 0;
	bool flag = false;
	fstream readFile;
	readFile.open(fileName);
	bool a;

	a = lastNameWithOnlyChar(Lastname);
	if (a == false)
	{
		cout << "Error The last name cannot be changed" << endl;
		return false;
	}
	if (readFile.fail())
	{
		cout << "Error The last name cannot be changed" << endl;
		return false;
	}
	vector<string>lines;
	string line;
	while (getline(readFile, line))
	{
		lines.push_back(line);
		counter++;
		if (line == email)
		{
			flag = true;
			lineNumber = counter - 3;
		}
	}
	readFile.close();
	ofstream writeFile;
	writeFile.open(fileName);
	if (writeFile.fail() || flag == false)
	{
		cout << "Error The last name cannot be changed" << endl;
		return false;
	}
	if (lineNumber == 0)
	{
		writeFile << text << endl;
		this->lastName = Lastname;
	}
	for (int i = 0; i < lines.size(); i++)
	{
		if (i != lineNumber)
		{
			writeFile << lines[i] << endl;
		}
		else
		{
			writeFile << text << endl;
			this->name = name;
		}
	}
	writeFile.close();
	return true;
}
bool Login::setPhone(const string phone) {
	string fileName = "users.txt";
	string text = phone;
	int lineNumber = 0, counter = 0;
	bool flag = false;
	fstream readFile;
	readFile.open(fileName);
	bool a;

	a = checkPhone(phone);
	if (a == false)
	{
		cout << "Error The phone cannot be changed" << endl;
		return false;
	}
	if (readFile.fail())
	{
		cout << "Error The phone cannot be changed" << endl;
		return false;
	}
	vector<string>lines;
	string line;
	while (getline(readFile, line))
	{
		lines.push_back(line);
		counter++;
		if (line == email)
		{
			flag = true;
			lineNumber = counter - 2;
		}
	}
	readFile.close();
	ofstream writeFile;
	writeFile.open(fileName);
	if (writeFile.fail() || flag == false)
	{
		cout << "Error The phone cannot be changed" << endl;
		return false;
	}
	if (lineNumber == 0)
	{
		writeFile << text << endl;
		this->phone = phone;
	}
	for (int i = 0; i < lines.size(); i++)
	{
		if (i != lineNumber)
		{
			writeFile << lines[i] << endl;
		}
		else
		{
			writeFile << text << endl;
			this->phone = phone;
		}
	}
	writeFile.close();
	return true;
}
bool Login::setID(const int ID) {
	string fileName = "users.txt";
	int text = ID;
	int lineNumber = 0, counter = 0;
	bool flag = false;
	fstream readFile;
	readFile.open(fileName);
	bool a;

	a = uniqueAndValidID(ID);
	if (a == false)
	{
		cout << "Error The ID cannot be changed" << endl;
		return false;
	}
	if (readFile.fail())
	{
		cout << "Error The ID cannot be changed" << endl;
		return false;
	}
	vector<string>lines;
	string line;
	while (getline(readFile, line))
	{
		lines.push_back(line);
		counter++;
		if (line == email)
		{
			flag = true;
			lineNumber = counter ;
		}
	}
	readFile.close();
	ofstream writeFile;
	writeFile.open(fileName);
	if (writeFile.fail() || flag == false)
	{
		cout << "Error The ID cannot be changed" << endl;
		return false;
	}
	if (lineNumber == 0)
	{
		writeFile << text << endl;
		this->ID = ID;
	}
	for (int i = 0; i < lines.size(); i++)
	{
		if (i != lineNumber)
		{
			writeFile << lines[i] << endl;
		}
		else
		{
			writeFile << text << endl;
			this->ID = ID;
		}
	}
	writeFile.close();
	return true;
}
bool Login::setEmail(const string email) {
	string fileName = "users.txt";
	string text = email;
	int lineNumber = 0, counter = 0;
	bool flag = false;
	fstream readFile;
	readFile.open(fileName);
	bool a;

	a = validEmail(email);
	if (a == false)
	{
		cout << "Error The ID cannot be changed" << endl;
		return false;
	}
	if (readFile.fail())
	{
		cout << "Error The ID cannot be changed" << endl;
		return false;
	}
	vector<string>lines;
	string line;
	while (getline(readFile, line))
	{
		lines.push_back(line);
		counter++;
		if (line == email)
		{
			flag = true;
			lineNumber = counter-1;
		}
	}
	readFile.close();
	ofstream writeFile;
	writeFile.open(fileName);
	if (writeFile.fail() || flag == false)
	{
		cout << "Error The ID cannot be changed" << endl;
		return false;
	}
	if (lineNumber == 0)
	{
		writeFile << text << endl;
		this->email = email;
	}
	for (int i = 0; i < lines.size(); i++)
	{
		if (i != lineNumber)
		{
			writeFile << lines[i] << endl;
		}
		else
		{
			writeFile << text << endl;
			this->email = email;
		}
	}
	writeFile.close();
	return true;
}
bool Login::setPassword(const string password, const string vpassword, const string vpassword2) {
	string fileName = "users.txt";
	string text = decryptPassword(vpassword);
	int lineNumber = 0, counter = 0;
	bool flag = false;
	fstream readFile;
	readFile.open(fileName);
	bool a,b;

	a = equalPassword(this->password,password);
	b = equalPassword(vpassword, vpassword2);
	if (a == false||b==false)
	{
		cout << "Error The password cannot be changed" << endl;
		return false;
	}
	if (readFile.fail())
	{
		cout << "Error The password cannot be changed" << endl;
		return false;
	}
	vector<string>lines;
	string line;
	while (getline(readFile, line))
	{
		lines.push_back(line);
		counter++;
		if (line == email)
		{
			flag = true;
			lineNumber = counter + 1;
		}
	}
	readFile.close();
	ofstream writeFile;
	writeFile.open(fileName);
	if (writeFile.fail() || flag == false)
	{
		cout << "Error The ID cannot be changed" << endl;
		return false;
	}
	if (lineNumber == 0)
	{
		writeFile <<  text << endl;
		this->vpassword = vpassword;
	}
	for (int i = 0; i < lines.size(); i++)
	{
		if (i != lineNumber)
		{
			writeFile << lines[i] << endl;
		}
		else
		{
			writeFile << text << endl;
			this->vpassword = vpassword;
		}
	}
	writeFile.close();
	return true;
}
bool Login::equalPassword(const  string password, const  string vpassword) {
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
bool Login::isLogin() {
	if (this != NULL)
	{
		if (this->login == false)
		{
			return false;
		}
		return true;
	}
	else return false;
}
bool Login::nameWithOnlyChar(const string name)
{
	for (int i = 0; i < int(name.length()); i++)
	{
		if ((name[i] > 65 && name[i] < 91) || (name[i] > 96 && name[i] < 123))
		{
			return true;
		}
		else {
			cout << "The name should contain only letters" << endl;
			return false;
		}
	}
}
bool Login::lastNameWithOnlyChar(const string lastName) {
	for (int i = 0; i < int(lastName.length()); i++)
	{
		if ((lastName[i] > 65 && lastName[i] < 91) || (lastName[i] > 96 && lastName[i] < 123) || (lastName[i] == '-' || lastName[i] == ' '))
		{
			return true;
		}
		else {
			cout << "The name should contain only letters" << endl;
			return false;
		}
	}
}
bool Login::checkPhone(const string phone)
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
bool Login::uniqueAndValidID(const int ID)
{
	string name, lastName, phone, email, password;
	int id;
	bool admin;
	int counter = 0, sum = 0, j = 1, y = 1;
	bool flag = false;
	ifstream inFile("users.txt");
	while (!inFile.eof())
	{
		inFile >> name >> lastName >> phone;
		inFile >> email >> id >> password >> admin;
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
	if (counter != 9)
	{
		cout << "There is an error in the ID number" << endl;
		return false;
	}
	if ((sum + (ID % 10)) % 10 == 0)
	{
		return true;
	}

}


bool Login::isChar(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}
bool Login::validEmail(const string email) {
	// Check the first character
	// is an alphabet or not
	if (!isChar(email[0])) {

		// If it's not an alphabet
		// email id is not valid
		cout << "There is a problem with the format of the email" << endl;
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
