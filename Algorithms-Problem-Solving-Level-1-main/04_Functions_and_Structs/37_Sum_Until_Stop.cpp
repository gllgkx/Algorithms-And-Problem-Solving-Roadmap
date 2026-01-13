# include <iostream>
# include <string>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

const int Exiting_Number = -99;

float Read_Number(string Message)
{
	float Number{};
	cout << Message << endl;
	cin >> Number;

	return Number;
}

double Calculate_Sum_Stream()
{
	float Number{};
	double Sum{};
	int Counter = 1;

	do
	{
		Number = Read_Number("Please enter Number " + to_string(Counter));

		if (Number == Exiting_Number)
		{
			break;
		}

		Sum += Number;
		Counter++;

	} while (Number != Exiting_Number);

	return Sum;
}

void Print_Result(double Number)
{
	Clear_Screen();
	cout << "Result = " << Number << endl;
}

int main()
{
	Print_Result(Calculate_Sum_Stream());
	return 0;

}
