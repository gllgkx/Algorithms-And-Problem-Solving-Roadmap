# include <iostream>
# include <string>
using namespace std;

void Clear_Screen() // This code clears the screen
{
	cout << "\033[2J\033[1;1H";
}

struct stTask_Duration
{
	int Days{};
	int Hours{};
	int Minutes{};
	int Seconds{};
};

int Read_Number(string Message)
{
	int Number{};
	bool FirstRun = true;

	do
	{
		if (!FirstRun)
		{
			cout << "Wrong Input! Enter Number > 0\n";
		}

		cout << Message << endl;
		cin >> Number;
		FirstRun = false;

	} while (Number < 0);

	return Number;
}

stTask_Duration Read_Task_Duration()
{
	stTask_Duration Task_Duration;

	Task_Duration.Days = Read_Number("Please enter Days:");
	Task_Duration.Hours = Read_Number("Please enter Hours:");
	Task_Duration.Minutes = Read_Number("Please enter Minutes:");
	Task_Duration.Seconds = Read_Number("Please enter Seconds:");

	return Task_Duration;
}

long long Calculate_Total_Seconds(stTask_Duration const& Task_Duration)
{
	const int Seconds_Per_Day = 24 * 60 * 60;
	const int Seconds_Per_Hours = 60 * 60;
	const int Seconds_Per_Minutes = 60;

	long long Total_Seconds{};

	Total_Seconds = (Task_Duration.Days * Seconds_Per_Day) + (Task_Duration.Hours * Seconds_Per_Hours)
		+ (Task_Duration.Minutes * Seconds_Per_Minutes) + Task_Duration.Seconds;

	return Total_Seconds;
}

void Print_Total_Seconds(stTask_Duration const& Task_Duration)
{
	Clear_Screen();
	cout << "Total Seconds: " << Calculate_Total_Seconds(Task_Duration) << endl;
}

int main()
{
	stTask_Duration Task_Duration = Read_Task_Duration();
	Print_Total_Seconds(Task_Duration);
	return 0;
}
