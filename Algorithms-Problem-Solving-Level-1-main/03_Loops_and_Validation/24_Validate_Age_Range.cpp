# include <iostream>
# include <string>
using namespace std;

void Clear_Screen() // This code will erase everything that came before from the screen
{
	cout << "\033[2J\033[1;1H";
}

int Get_User_Age()
{
	int Age = {};
	cout << "Please enter your age:\n";
	cin >> Age;
	return Age;
}

bool Validate_Number_In_Range(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

void Print_Result(int Age)
{
	Clear_Screen();
	if (Validate_Number_In_Range(Age, 18, 45))
		cout << Age << " is a vaild age\n";
	else
		cout << Age << " is invaild age\n";
}

int main()
{

	Print_Result(Get_User_Age());
	return 0;
}