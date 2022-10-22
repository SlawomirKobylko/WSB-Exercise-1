#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <cstdlib>

using namespace std;


class User
{
public:
	string name;
	string email;
	string password;

	User(string x, string y, string z)
	{
		name = x;
		email = y;
		password = z;
	}
	User() {};

	void Registration();
	void Logon();
};

vector<User>Users;
User NewUser;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void User::Registration()
{
	cout << "You're choose registration" << endl;
	cout << "Enter your Name: ";				cin >> NewUser.name;
	cout << "Enter your Email: ";				cin >> NewUser.email;
	cout << "Enter your Password: ";			cin >> NewUser.password;

	Users.push_back(NewUser);

	fstream file; 

	file.open("dataa.txt", ios::out); //ios::app

	file << NewUser.name << endl;
	file << NewUser.email << endl;
	string str = NewUser.password;
	for (int i = 0; (i < 100 && str[i] != '\0'); i++)
		//str[i] = str[i] + 600; //the key for encryption is 3 that is added to ASCII value - sposob A
		str[i] = '*';

	file << str << endl;
	file.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void User::Logon()
{
	fstream file_;
	file_.open("dataa.txt", ios::out);
	if (file_.good() == false)
	{
		cout << "This file cannot exist";
		exit(0);
	}
	cout << "You're choose Logon" << endl;
	//string name_, email_, password_;
	cout << "Enter your Name: ";				cin >> name;
	if (name != NewUser.name)
	{
		cout << "Incorrect User name" << endl;
	}
	cout << "Enter your Email: ";				cin >> email;
	if (email != NewUser.email)
	{
		cout << "Incorrect email" << endl;
	}
	cout << "Enter your Password: ";			cin >> password;
	if (password != NewUser.password)
	{
		cout << "Incorrect password" << endl;
	}
	else
	{
		cout << "This password has been encrypted!" << endl;
	}
	file_ << NewUser.name << endl;
	file_ << NewUser.email << endl;
	file_ << NewUser.password << endl;

	cout << name << endl;
	cout << email << endl;
	cout << password << endl;

	file_.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int number;
	cout << "Welcome!!! \nChoose an options:" << endl;
	cout << "Registration -  click 1" << endl;
	cout << "Log in  - click 2" << endl;
	cin >> number;
	switch (number)
	{
	case 1:
		NewUser.Registration();
		break;
	case 2:
		NewUser.Logon();
		break;
	default: 
		cout << "Bad number" << endl;
		break;
	}
}