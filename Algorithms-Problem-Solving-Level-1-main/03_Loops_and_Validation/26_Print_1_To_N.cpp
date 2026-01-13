# include <iostream>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

int Get_User_Number()
{
	int Number{};

	cout << "Please enter number:\n";
	cin >> Number;

	return Number;
}

void Print_Range_From_1toN(int Number)
{
	Clear_Screen();
	cout << "Range Printed:\n";
	for (int i = 1; i <= Number; i++)
		cout << i << endl;
}

int main()
{
	Print_Range_From_1toN(Get_User_Number());
	return 0;
}