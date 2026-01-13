# include <iostream>
using namespace std;

struct stInfo
{
	float a = 0, h = 0;
};

stInfo Read_Number()
{
	stInfo info;

	cout << "Please Enter Triangle Base A ?\n";
	cin >> info.a;
	cout << "Please Enter Triangle height H ?\n";
	cin >> info.h;
	return info;
}

float Calculate_Triangle_Area(stInfo info)
{
	return (0.5 * info.a * info.h);
}

void Print_Result(float Area)
{
	system("cls"); // This code will erase everything that came before from the screen
	cout << "Triangle Area : " << Area << endl;
}

int main()
{
	Print_Result(Calculate_Triangle_Area(Read_Number()));
	return 0;
}