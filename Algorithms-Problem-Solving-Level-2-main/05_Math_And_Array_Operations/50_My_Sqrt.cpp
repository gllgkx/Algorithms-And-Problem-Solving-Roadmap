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

float MySqrt(float Number)
{
    if (Number <= 0) return 0;

    float Guess = Number / 2.0;
    float Last_Guess{};

    for (int i = 0; i < 20; i++)
    {
        Last_Guess = Guess;

        Guess = (Guess + (Number / Guess)) / 2;

        if (Guess == Last_Guess)
        {
            break;
        }
    }

    return Guess;
}

int main()
{
    float Number = Read_Number("Please enter a number: ");

    MyLib::Clear_Screen();

    cout << "My Sqrt Result : " << MySqrt(Number) << endl;
    cout << "C++ Sqrt Result: " << sqrt(Number) << endl;

    return 0;
}