# include <iostream>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

enum enStatus_Number { Even = 1, Odd = 2 };

int Get_User_Number()
{
	int Number{};

	cout << "Please enter number:\n";
	cin >> Number;

	return Number;
}

enStatus_Number Check_Status_Number(int Number)
{
	if (Number % 2 != 0)
		return enStatus_Number::Odd;
	else
		return enStatus_Number::Even;
}

int Calculate_Odd_Number(int Number)
{
	int Sum{};
	for (int i = 1; i <= Number; i++)
	{
		if(Check_Status_Number(i) == enStatus_Number::Odd)
			Sum += i;
	}
	return Sum;
}

int main()
{
	int Num = Get_User_Number();
	Clear_Screen();

	cout << "Odd Number = " << Calculate_Odd_Number(Num);
	return 0;
}