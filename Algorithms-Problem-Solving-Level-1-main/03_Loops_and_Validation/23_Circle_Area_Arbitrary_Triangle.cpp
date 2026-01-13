# define _USE_MATH_DEFINES
# include <iostream>
# include <cmath>
using namespace std;

void Clear_Screen() // This code will erase everything that came before from the screen
{
	cout << "\033[2J\033[1;1H";
}

struct stTriangle_Data
{
	float a = {};
	float b = {};
	float c = {};
};

float Get_Positive_Number(string Message)
{
	float Num = {};
	do
	{
		cout << Message << endl;
		cin >> Num;

		if (Num <= 0)
		{
			Clear_Screen();
			cout << "Wrong Input! Number must be > 0\n";
		}
	} while (Num <= 0);
		return Num;
}

stTriangle_Data Read_Triangle_Data()
{
	stTriangle_Data info;

	info.a = Get_Positive_Number("Please enter triangle side A:");
	info.b = Get_Positive_Number("Please enter triangle base B:");
	info.c = Get_Positive_Number("Please enter triangle side C:");

	return info;
}

double Circle_Area_By_ATriangle(const stTriangle_Data& info)
{
	double P = ((info.a + info.b + info.c) / 2);
	double T_1 = (info.a * info.b * info.c);
	double T_2 = (4 * sqrt(P * (P - info.a) * (P - info.b) * (P - info.c)));
	double Area = M_PI * pow((T_1 / T_2), 2);
	return Area;
}

void Print_Result(double Area)
{
	Clear_Screen();
	cout << "Circle Area = " << Area << endl;
}

int main()
{
	stTriangle_Data info = Read_Triangle_Data();
	Print_Result(Circle_Area_By_ATriangle(info));
	return 0;
}