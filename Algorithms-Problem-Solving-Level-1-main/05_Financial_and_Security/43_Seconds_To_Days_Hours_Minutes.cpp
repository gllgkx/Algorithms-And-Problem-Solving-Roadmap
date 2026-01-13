# include <iostream>
using namespace std;

struct stTask_Duration
{
	int Days{};
	int Hours{};
	int Minutes{};
	int Seconds{};
};

void Clear_Screen() // This code clears the screen
{
	cout << "\033[2J\033[1;1H";
}

long long Read_Total_Seconds(string Message)
{
	long long Total_Seconds{};
	bool FirstRun = true;

	do
	{
		if (!FirstRun)
		{
			Clear_Screen();
			cout << "Wrong Input! Enter Number > 0\n";
		}

		cout << Message << endl;
		cin >> Total_Seconds;
		FirstRun = false;

	} while (Total_Seconds <= 0);

	return Total_Seconds;
}

stTask_Duration Seconds_To_Task_Duration(long long Total_Seconds)
{
	stTask_Duration Task_Duration;
	long long Remainder{};
	const int Second_Per_Day = 24 * 60 * 60;
	const int Second_Per_Hour = 60 * 60;
	const int Second_Per_Minute = 60;

	Task_Duration.Days = floor(Total_Seconds / Second_Per_Day);
	Remainder = Total_Seconds % Second_Per_Day;

	Task_Duration.Hours = floor(Remainder / Second_Per_Hour);
	Remainder %= Second_Per_Hour;

	Task_Duration.Minutes = floor(Remainder / Second_Per_Minute);
	Remainder %= Second_Per_Minute;

	Task_Duration.Seconds = Remainder;

	return Task_Duration;
}

void Print_Result(stTask_Duration const& Task_Duration)
{
	Clear_Screen();
	cout << Task_Duration.Days << " Days : ";
	cout << Task_Duration.Hours << " Hours : ";
	cout << Task_Duration.Minutes << " Minutes : ";
	cout << Task_Duration.Seconds << " Seconds ";
}

int main()
{
	long long Total_Seconds = Read_Total_Seconds("Please enter Total Seconds:");
	Print_Result(Seconds_To_Task_Duration(Total_Seconds));
	return 0;
}