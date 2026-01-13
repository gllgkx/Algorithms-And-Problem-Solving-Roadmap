# include <iostream>
using namespace std;

void Read_Number(float& A, float& B)
{
	cout << "Please Enter A ?\n";
	cin >> A;
	cout << "Please Enter B ?\n";
	cin >> B;
}

float Calculate_Area(float A, float B)
{
	return A * B;
}

void Print_Area(float Area)
{
	cout << "Rectangle Area : " << Area << endl;
}

int main()
{
	float A = 0, B = 0;
	Read_Number(A, B);

	system("cls"); // This code will erase everything that came before from the screen
	Print_Area(Calculate_Area(A, B));
	return 0;
}