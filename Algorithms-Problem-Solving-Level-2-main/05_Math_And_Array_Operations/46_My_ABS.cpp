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

float MyABS(float Number)
{
	if (Number < 0)
		return -Number;
	else
		return Number;
}

int main()
{
	float Number = Read_Number("Please enter a number: ");

	MyLib::Clear_Screen();

	cout << "My abs Result : " << MyABS(Number) << endl;
	cout << "C++ abs Result: " << abs(Number) << endl;

	return 0;
}