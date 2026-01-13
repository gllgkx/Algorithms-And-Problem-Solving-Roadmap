# define USE_MATH_DEFINES
# include <iostream>
# include <string>
# include <cmath>
using namespace std;

enum enOperation_Type { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

struct stUser_Input
{
	double Number[2];
	enOperation_Type Type;
};

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

double Read_Number(string Message)
{
	double Number{};

	cout << Message << endl;
	cin >> Number;

	return Number;
}

enOperation_Type Read_Type(string Message)
{
	char Type = '+';
	bool FirstRun = true;

	do
	{
		if (!FirstRun)
		{
			Clear_Screen();
			cout << "Wrong Operation! Please try again.\n";
		}

		cout << Message << endl;
		cin >> Type;
		FirstRun = false;

	} while (Type != '+' && Type != '-' && Type != '/' && Type != '*');

	return (enOperation_Type)Type;
}

stUser_Input Get_User_Info()
{
	stUser_Input info;
	info.Number[0] = Read_Number("Please enter a Number 1:");
	info.Type = Read_Type("Please enter a Operation type: (+,-,*,/)");
	info.Number[1] = Read_Number("Please enter a Number 2:");
	return info;
}

long double Calculate(stUser_Input const& info)
{
	switch (info.Type)
	{
	case enOperation_Type::Add:
		return (info.Number[0] + info.Number[1]);
	case enOperation_Type::Subtract:
		return (info.Number[0] - info.Number[1]);
	case enOperation_Type::Multiply:
		return (info.Number[0] * info.Number[1]);
	case enOperation_Type::Divide:
		return (info.Number[0] / info.Number[1]);
	default:
		return 0;
	}
}

void Print_Result(stUser_Input const& info)
{
	Clear_Screen();
	if (info.Type == enOperation_Type::Divide)
	{
		if (info.Number[1] == 0)
			cout << "Cannot divide by 0" << endl;
		else
			cout << "Result = " << Calculate(info) << endl;
	}
	else
		cout << "Result = " << Calculate(info) << endl;
}

int main()
{
	Print_Result(Get_User_Info());
	return 0;

}
