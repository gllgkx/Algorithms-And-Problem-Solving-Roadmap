# include <iostream>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

struct stPiggy_Bank_Content
{
	int Penny{};
	int Nickel{};
	int Dime{};
	int Quarter{};
	int Dollar{};
};

const int Penny_Value   = 1;
const int Nickel_Value  = 5;
const int Dime_Value    = 10;
const int Quarter_Value = 25;
const int Dollar_Value  = 100;

int Get_User_Number(string Message)
{
	int Number;

	do
	{
		cout << Message << endl;
		cin >> Number;

		if (Number <= 0)
		{
			Clear_Screen();
			cout << "Wrong Input!" << endl;
		}
	} while (Number <= 0);
	return Number;
}

stPiggy_Bank_Content Read_Piggy_Bank()
{
	stPiggy_Bank_Content info;

	info.Penny   = Get_User_Number("Please enter a Total Penny:");
	info.Nickel  = Get_User_Number("Please enter a Total Nickel:");
	info.Dime    = Get_User_Number("Please enter a Total Dime:");
	info.Quarter = Get_User_Number("Please enter a Total Quarter:");
	info.Dollar  = Get_User_Number("Please enter a Total Dollar:");

	return info;
}

int Calculate_Total_Pennies(stPiggy_Bank_Content const &info)
{
	int Total_Pennies{};

	Total_Pennies = ((info.Penny * Penny_Value) + (info.Nickel * Nickel_Value) + (info.Dime * Dime_Value) + (info.Quarter * Quarter_Value) + (info.Dollar * Dollar_Value));
	return Total_Pennies;
}

float Calculate_Total_Dollars(float Pennies)
{
	return (Pennies / 100);
}

void Print_Result(stPiggy_Bank_Content const& info)
{
	Clear_Screen();
	float Total_Pennies = Calculate_Total_Pennies(info);
	cout << "Total Pennies = " << Total_Pennies << endl;
	cout << "Total Dollars = " << Calculate_Total_Dollars(Total_Pennies) << endl;
}

int main()
{
	Print_Result(Read_Piggy_Bank());
	return 0;
}