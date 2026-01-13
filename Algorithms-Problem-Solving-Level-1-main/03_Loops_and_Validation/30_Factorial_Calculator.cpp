# include <iostream>
# include <string>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

int Get_Positive_Number(string Message)
{
	int Number{};

	do
	{
		cout << Message << endl;
		cin >> Number;

		if (Number < 0)
		{
			Clear_Screen();
			cout << "Wrong input! " << to_string(Number) << " is not a positive number\n";
		}
	} while (Number < 0);
	return Number;
}

long long Calculate_Factorial_Number(int Number)
{
	long long Result = 1;
	for (int i = Number; i >= 1; i--)
		Result *= i;
	return Result;
}

void Print_Result(int Number)
{
	Clear_Screen();
	cout << "Factorial = " << Calculate_Factorial_Number(Number) << endl;
}

int main()
{
	Print_Result(Get_Positive_Number("Please enter number :"));
	return 0;
}