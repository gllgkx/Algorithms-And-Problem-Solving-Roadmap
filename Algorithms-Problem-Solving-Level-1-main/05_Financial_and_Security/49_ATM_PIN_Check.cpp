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
	int Attempt = 1;
	string Password{};

	do
	{
		Password = Read_PIN_Code();

		if (PIN == Password)
		{
			return true;
		}
		else
		{
			Clear_Screen();
			cout << "Wrong PIN! Attempt " + to_string(Attempt) << endl;
			system("color 4F"); // Turn screen to Red
		}

		Attempt++;
	} while (Password != PIN);

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

	Login(PIN);
	Print_Result(Balance);

	return 0;
}