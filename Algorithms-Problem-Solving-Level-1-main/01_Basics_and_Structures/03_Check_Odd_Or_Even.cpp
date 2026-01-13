# include <iostream>
# include <string>
using namespace std;

enum enNumberType { ODD = 1, Even = 2 };

int ReadNumber()
{
	int Number;
	cout << "Please Enter Name:\n";
	cin >> Number;
	return Number;
}

enNumberType Check_Number_Type(int Num)
{
	int Result = Num % 2;
	if (Result == 0)
	{
		return enNumberType::Even;
	}
	else
	{
		return enNumberType::ODD;
	}
}

void PrintNumberType(enNumberType NumberType)
{
	if (NumberType == enNumberType::Even)
	{
		cout << "\n Number is Even. \n";
	}
	else
	{
		cout << "\n Number is ODD. \n";
	}
}

int main()
{
	PrintNumberType(Check_Number_Type(ReadNumber()));
	return 0;
}