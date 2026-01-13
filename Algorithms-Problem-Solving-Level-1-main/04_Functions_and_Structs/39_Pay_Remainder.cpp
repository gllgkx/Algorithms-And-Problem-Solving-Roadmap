# include <iostream>
# include <string>
# include <cmath>
using namespace std;

struct stUser_Input
{
	double Total_Bill{}, Cash_Paid{};
};

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

double Read_Positive_Number(string Message)
{
	double Number{};
	bool FirstRun = true;

	do
	{
		if (!FirstRun)
		{
			Clear_Screen();
			cout << "Wrong Input! Enter Number > 0\n";
		}

		cout << Message << endl;
		cin >> Number;
		FirstRun = false;

	} while (Number <= 0);

	return Number;
}

stUser_Input Read_Input()
{
	stUser_Input info;

	info.Total_Bill = Read_Positive_Number("Please enter a Total Bill");
	info.Cash_Paid = Read_Positive_Number("Please enter a Cash Paid");

	return info;
}

double Calculate_Remainder(stUser_Input const& info)
{
	double Result{};

	Result = info.Cash_Paid - info.Total_Bill;

	return Result;
}

void Print_Remainder(stUser_Input const& info)
{
	double Remainder = Calculate_Remainder(info);

	Clear_Screen();

	cout << "Total Bill = " << info.Total_Bill << endl;
	cout << "Total Cash Paid = " << info.Cash_Paid << endl;
	cout << "==========================\n";

	if (info.Total_Bill > info.Cash_Paid)
		cout << "Transaction declined! Please pay the remaining amount: " << abs(Remainder) << endl;
	else
		cout << "Remainder = " << Remainder;
}

int main()
{
	stUser_Input info = Read_Input();
	Print_Remainder(info);
	return 0;
}