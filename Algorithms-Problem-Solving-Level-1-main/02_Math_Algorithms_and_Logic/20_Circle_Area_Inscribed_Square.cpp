# define _USE_MATH_DEFINES
# include <iostream>
# include <cmath>
using namespace std;

void Clear_Screen() // This code will erase everything that came before from the screen
{
	cout << "\033[2J\033[1;1H";
}

float Read_Square_Side()
{
	float A = {};
	do
	{
		cout << "Please Enter square side A ?\n";
		cin >> A;
		
		if (A <= 0)
			cout << "Wrong Input\n";
		
	} while (A <= 0);
	return A;
}

double Circle_Area_Inscribed_InSquare(float A)
{
	return (M_PI * (pow((A / 2), 2)));
}

void Print_Result(double Area)
{
	Clear_Screen();
	cout << "Circle Area : " << Area << endl;
}

int main()
{
	Print_Result(Circle_Area_Inscribed_InSquare(Read_Square_Side()));
	return 0;
}