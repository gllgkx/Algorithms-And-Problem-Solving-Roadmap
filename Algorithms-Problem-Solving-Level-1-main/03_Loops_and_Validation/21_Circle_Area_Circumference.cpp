# define _USE_MATH_DEFINES
# include <iostream>
# include <cmath>
using namespace std;

void Clear_Screen() // This code will erase everything that came before from the screen
{
	cout << "\033[2J\033[1;1H";
}

float Read_Circumference()
{
	float l = {};

	do
	{
		cout << "Please Enter Circumference L ?\n";
		cin >> l;

		Clear_Screen();
		if (l <= 0)
			cout << "Wrong Input\n";
	} while (l <= 0);
	return l;
}

double Circle_Area_By_Circumference(float l)
{
	return (l * l / (4 * M_PI));
}

void PrintResult(double Area)
{
	Clear_Screen();
	cout << "Circle Area = " << Area << endl;
}

int main()
{
	PrintResult(Circle_Area_By_Circumference(Read_Circumference()));
	return 0;
}