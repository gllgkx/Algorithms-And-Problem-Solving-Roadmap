# include <iostream>
# include <string>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

int Get_User_Age()
{
	int Age = {};
	cout << "Please enter your age between 18 and 45: " << endl;
	cin >> Age;
	return Age;
}

bool Validate_Number_In_Range(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

int Read_Until_Age_Between(int From, int To)
{
	int Age = {};

	do
	{
		Age = Get_User_Age();

		if (!Validate_Number_In_Range(Age, From, To))
		{
			Clear_Screen();
			cout << "Wrong Input!\n";
		}

	} while (!Validate_Number_In_Range(Age, From, To));

	return Age;
}

void PrintResult(int Age)
{
	cout << "Your Age is: " << Age << endl;
}

int main()
{
	PrintResult(Read_Until_Age_Between(18,45));
	return 0;
}