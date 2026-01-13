# include <iostream>
# include <string>
using namespace std;

enum enDay_Of_Week { Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thu = 5, Fri = 6, Sat = 7 };


void Clear_Screen() // This code clears the screen
{
	cout << "\033[2J\033[1;1H";
}

int Read_Number_In_Range(int From, int To)
{
	int Choice{};
	bool FirstRun = true;

	do
	{
		Clear_Screen();

		cout << "[1] Sunday\n";
		cout << "[2] Monday\n";
		cout << "[3] Tuesday\n";
		cout << "[4] Wednesday\n";
		cout << "[5] Thursday\n";
		cout << "[6] Friday\n";
		cout << "[7] Saturday\n";
		cout << "=======================\n";

		if (!FirstRun)
		{
			cout << "Wrong Choice! Enter Number From " + to_string(From) + " To " + to_string(To) << endl;
		}

		cout << "Please enter a Choice: \n";
		cin >> Choice;

		FirstRun = false;
	} while (Choice < From || Choice > To);

	return Choice;
}

enDay_Of_Week Read_Day()
{
	const int From = 1, To = 7;

	return (enDay_Of_Week)Read_Number_In_Range(From,To);
}

string Get_Day_Name(enDay_Of_Week const& Day)
{
	switch (Day)
	{
	case enDay_Of_Week::Sun: return "Sunday";
	case enDay_Of_Week::Mon: return "Monday";
	case enDay_Of_Week::Tue: return "Tuesday";
	case enDay_Of_Week::Wed: return "Wednesday";
	case enDay_Of_Week::Thu: return "Thursday";
	case enDay_Of_Week::Fri: return "Friday";
	case enDay_Of_Week::Sat: return "Saturday";
	default: return "Unknown Day";
	}
}

void Print_Day(string const& Day)
{
	Clear_Screen();
	cout << "Day is " << Day << endl;
}

int main()
{
	Print_Day(Get_Day_Name(Read_Day()));
	return 0;
}