# define _USE_MATH_DEFINES
# include <iostream>
# include <cmath>
using namespace std;

float Read_Diameter()
{
	float D = {};
	cout << "Please Enter Diameter D ?\n";
	cin >> D;
	return D;
}

double Circle_Area_By_Diameter(float D)
{
	return ((M_PI * pow(D, 2)) / 4);
}

void Print_Result(double Area)
{
	system("cls"); // This code will erase everything that came before from the screen
	cout << "Circle Area : " << Area << endl;
}

int main()
{
	Print_Result(Circle_Area_By_Diameter(Read_Diameter()));
}