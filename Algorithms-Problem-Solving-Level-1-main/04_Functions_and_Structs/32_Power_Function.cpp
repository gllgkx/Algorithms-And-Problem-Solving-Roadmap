# include <iostream>
# include <string>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

struct stInput_User
{
	int Number{};
	int Power{};
};

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
			cout << "Wrong Input! " << to_string(Number) << " is not a positive number\n";
		}
	} while (Number < 0);
	return Number;
}

stInput_User Read_Info()
{
	stInput_User info;
	
	info.Number = Get_Positive_Number("Please Enter Number:");
	info.Power = Get_Positive_Number("Please Enter Power:");

	return info;
}


long long Calculate_Power(stInput_User const &info)
{
	if (info.Power == 0)
		return 1;

	long long Result = 1;
	for (int i = 1; i <= info.Power; i++)
	{
		Result = Result * info.Number;
	}
	return Result;
}

void Print_Result(stInput_User info)
{
	Clear_Screen();
	cout << "Number^" << info.Power << " = " << Calculate_Power(info) << endl;
}

int main()
{
	Print_Result(Read_Info());
	return 0;

}
