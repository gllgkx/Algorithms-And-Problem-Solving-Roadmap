# include <iostream>
# include <cmath>
using namespace std;

void Read_Number(float& a,float& d)
{
	cout << "Please Enter a ?\n";
	cin >> a;
	cout << "Please Enter d ?\n";
	cin >> d;
}

float Rectangle_Area_By_Side_And_Diagonal(int a, int d)
{
	return (a * sqrt(pow(d,2)-pow(a,2)));
}

void Print_Result(float Area)
{
	cout << "Area = " << Area << endl;
}

int main()
{
	float a = 0, d = 0;
	Read_Number(a, d);

	system("cls"); // This code will erase everything that came before from the screen
	Print_Result(Rectangle_Area_By_Side_And_Diagonal(a, d));
	return 0;
}