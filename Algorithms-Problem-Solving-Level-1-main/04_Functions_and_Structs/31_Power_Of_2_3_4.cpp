# include <iostream>
# include <string>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

int Get_Number()
{
	int Number{};
	do
	{
		cout << "Please Enter Number:\n";
		cin >> Number;

		if (Number < 0)
		{
			Clear_Screen();
			cout << "Wrong Input! " << to_string(Number) << " is not a positive number\n";
		}

	} while (Number < 0);
	return Number;
}

long long Calculate_Power(int Number, int Power)
{
	long long Result = 1;
	for (int i = 1; i <= Power; i++)
	{
		Result = Result * Number;
	}
	return Result;
}

void Print_Result(int Number)
{
	Clear_Screen();
	cout << "Number^2 = " << Calculate_Power(Number, 2) << endl;
	cout << "Number^3 = " << Calculate_Power(Number, 3) << endl;
	cout << "Number^4 = " << Calculate_Power(Number, 4) << endl;

}

int main()
{
	Print_Result(Get_Number());
	return 0;

}
