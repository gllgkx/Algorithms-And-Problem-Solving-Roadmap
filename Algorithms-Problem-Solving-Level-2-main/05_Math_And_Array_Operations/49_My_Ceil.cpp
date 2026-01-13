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

int MyCeil(float Number)
{
	if (Number > 0)
	{
		if (Number == (int)Number)
			return Number;
		else
			return (int)Number + 1;
	}
	else
		return (int)Number;
}

int main()
{
	float Number = Read_Number("Please enter a number: ");

	MyLib::Clear_Screen();

	cout << "My MyCeil Result : " << MyCeil(Number) << endl;
	cout << "C++ Ceil Result: " << ceil(Number) << endl;

	return 0;
}