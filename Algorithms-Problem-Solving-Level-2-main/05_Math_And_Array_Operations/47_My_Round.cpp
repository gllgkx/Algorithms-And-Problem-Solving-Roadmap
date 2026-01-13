# include <iostream>
# include <string>
# include <cmath>
# include "MyLib.h" // Project-specific Library
using namespace std;

float Read_Number(const std::string& Message)
{
	float Number{};

	cout << Message;
	cin >> Number;

	return Number;
}

int MyRound(float Number)
{
	if (Number > 0)
		return (int)(Number + 0.5);
	else
		return (int)(Number - 0.5);
}

int main()
{
	float Number = Read_Number("Please enter a number: ");

	MyLib::Clear_Screen();

	cout << "My MyRound Result : " << MyRound(Number) << endl;
	cout << "C++ Round Result: " << round(Number) << endl;

	return 0;
}