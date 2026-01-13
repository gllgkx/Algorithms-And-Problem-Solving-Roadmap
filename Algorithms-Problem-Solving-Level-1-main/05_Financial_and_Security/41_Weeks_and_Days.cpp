# include <iostream>
# include <string>
using namespace std;

const int Hours_Per_Day = 24;
const int Hours_Per_Weeks = (Hours_Per_Day * 7);

void Clear_Screen() // This code clears the screen
{
	cout << "\033[2J\033[1;1H";
}

double Read_Total_Hours(string Message)
{
	double Total_Hours{};
	bool FirstRun = true;

	do
	{
		if (!FirstRun)
		{
			Clear_Screen();
			cout << "Wrong Input! Enter Number > 0\n";
		}

		cout << Message << endl;
		cin >> Total_Hours;
		FirstRun = false;

	} while (Total_Hours <= 0);

	return Total_Hours;
}


double Calculate_Hours_To_Weeks(double Total_Hours)
{
	return (Total_Hours / Hours_Per_Weeks);
}

double Calculate_Hours_To_Days(double Total_Hours)
{
	return (Total_Hours / Hours_Per_Day);
}

void Print_Hours_Weeks_And_Day(double Total_Hours)
{
	Clear_Screen();

	cout << "Weeks = " << Calculate_Hours_To_Weeks(Total_Hours) << endl;
	cout << "Days = " << Calculate_Hours_To_Days(Total_Hours) << endl;
}

int main()
{
	Print_Hours_Weeks_And_Day(Read_Total_Hours("Please enter Total Hours:"));
	return 0;
}