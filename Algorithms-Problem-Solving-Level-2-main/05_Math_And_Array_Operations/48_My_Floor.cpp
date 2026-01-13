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

int MyFloor(float Number)
{
    if (Number >= 0)
        return (int)Number;
    else // Negative
    {
        if (Number == (int)Number) 
            return Number;
        else
            return (int)Number - 1;
    }
}

int main()
{
	float Number = Read_Number("Please enter a number: ");

	MyLib::Clear_Screen();

	cout << "My MyFloor Result : " << MyFloor(Number) << endl;
	cout << "C++ Floor Result: " << floor(Number) << endl;

	return 0;
}