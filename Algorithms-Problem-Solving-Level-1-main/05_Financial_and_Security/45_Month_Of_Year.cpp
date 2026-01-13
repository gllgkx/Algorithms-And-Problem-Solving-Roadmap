# include <iostream>
# include <string>
using namespace std;

enum enMonth_Of_Year { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

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

		cout << "[1] January\n";
		cout << "[2] February\n";
		cout << "[3] March\n";
		cout << "[4] April\n";
		cout << "[5] May\n";
		cout << "[6] June\n";
		cout << "[7] July\n";
		cout << "[8] August\n";
		cout << "[9] September\n";
		cout << "[10] October\n";
		cout << "[11] November\n";
		cout << "[12] December\n";
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

enMonth_Of_Year Read_Month()
{
	const int From = 1, To = 12;

	return (enMonth_Of_Year)Read_Number_In_Range(From,To);
}

string Get_Month_Name(enMonth_Of_Year const& Month)
{
	switch (Month)
	{
	case enMonth_Of_Year::Jan: return "January";
	case enMonth_Of_Year::Feb: return "February";
	case enMonth_Of_Year::Mar: return "March";
	case enMonth_Of_Year::Apr: return "April";
	case enMonth_Of_Year::May: return "May";
	case enMonth_Of_Year::Jun: return "June";
	case enMonth_Of_Year::Jul: return "July";
	case enMonth_Of_Year::Aug: return "August";
	case enMonth_Of_Year::Sep: return "September";
	case enMonth_Of_Year::Oct: return "October";
	case enMonth_Of_Year::Nov: return "November";
	case enMonth_Of_Year::Dec: return "December";
	default: return "Unknown Month";
	}
}

void Print_Month(string const& Month)
{
	Clear_Screen();
	cout << "Month is " << Month << endl;
}

int main()
{
	Print_Month(Get_Month_Name(Read_Month()));
	return 0;
}