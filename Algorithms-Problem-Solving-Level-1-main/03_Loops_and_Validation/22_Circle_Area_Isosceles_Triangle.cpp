# define _USE_MATH_DEFINES
# include <iostream>
# include <cmath>
using namespace std;

void Clear_Screen() // This code will erase everything that came before from the screen
{
	cout << "\033[2J\033[1;1H";
}

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

void Read_Triangle_Data(float& A, float& B)
{
	A = Get_Positive_Number("Please enter triangle side A");
	B = Get_Positive_Number("Please enter triangle base B");
}

double Circle_Area_By_ITriangle(const float& A, const float& B)
{
	double Area = (M_PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B)));
	return Area;
}

void Print_Result(double Area)
{
	Clear_Screen();

	cout << "Area = " << Area << endl;
}

int main()
{
	float A = {}, B = {};
	Read_Triangle_Data(A, B);

	Print_Result(Circle_Area_By_ITriangle(A, B));
	return 0;
}