# include <iostream>
# include <string>
# include "MyLib.h" // Project-specific Library
using namespace std;
using namespace MyLib;

string Read_PIN_Code()
{
	string Password{};

	cout << "Please enter a Password:" << endl;
	cin >> Password;

	return Password;
}

bool Login(string const& PIN)
{
	string Password{};
	int Attempt{};

	do
	{
		Password = Read_PIN_Code();
		Attempt++;

		if (Password == PIN)
			return true;
		else
		{
			Clear_Screen();
			cout << "Wrong PIN! you have " + to_string(3 - Attempt) + " more attempt" << endl;
		}

	} while (Password != PIN && Attempt < 3);

	return (Password == PIN);
}

void Print_Result(double Balance)
{
	Clear_Screen();
	system("color 2F"); //Turn screen to green
	cout << "Balance = " << Balance << endl;
}

int main()
{
	const string PIN = "1234";
	double Balance = 12550.55;

	if (Login(PIN))
		Print_Result(Balance);
	else
	{
		Clear_Screen();
		system("color 4F"); // Turn screen to Red
		cout << "Card is locked!" << endl;
	}
	return 0;
}