# include <iostream>
using namespace std;

const double Service_Fee = 0.1;
const double Sales_Tax = 0.16;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

double Read_Bill_Value(string Message)
{
	double Bill_Value{};
	bool FirstRun = true;

	do
	{
		if (!FirstRun)
		{
			Clear_Screen();
			cout << "Wrong Input! Enter Number > 0\n";
		}

		cout << Message << endl;
		cin >> Bill_Value;
		FirstRun = false;

	} while (Bill_Value <= 0);

	return Bill_Value;
}

double Calculate_Total_Bill(double const& Bill_Value)
{
	double Total_Bill{};

	Total_Bill = Bill_Value * (Service_Fee + 1);
	Total_Bill *= (Sales_Tax + 1);

	return Total_Bill;
}

void Print_Result(double Bill_Value)
{
	Clear_Screen();
	cout << "Bill Value = " << Bill_Value << endl;
	cout << "Total Bill = " << Calculate_Total_Bill(Bill_Value) << endl;
}

int main()
{
	double Bill_Value = Read_Bill_Value("Please enter a Bill Value");
	Print_Result(Bill_Value);

	return 0;
}