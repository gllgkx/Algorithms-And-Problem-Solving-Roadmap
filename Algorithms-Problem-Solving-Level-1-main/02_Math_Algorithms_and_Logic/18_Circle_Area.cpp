# define _USE_MATH_DEFINES
# include <iostream>
# include <cmath>
using namespace std;

float Read_Radious()
{
	float r = {};
	cout << "Please Enter Radious R ?\n";
	cin >> r;
	return r;
}

double Calculate_Circle_Area(float r)
{
	return (M_PI * pow(r, 2));
}

void Print_Result(double Area)
{
	system("cls"); // This code will erase everything that came before from the screen
	cout << "Circle Area : " << Area << endl;
}

int main()
{
	Print_Result(Calculate_Circle_Area(Read_Radious()));
}