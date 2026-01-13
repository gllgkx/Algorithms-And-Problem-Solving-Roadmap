# include <iostream>
# include <string>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

enum enPrim_NotPrime { Prime = 1, Not_Prime = 2 };

int Get_Positive_Number()
{
	int Number{};
	bool FirstRun = true;

	do
	{
		if (!FirstRun)
		{
			Clear_Screen();
			cout << "Wrong Input! " << to_string(Number) << " is not a positive number\n";
		}

		cout << "Please enter Number" << endl;
		cin >> Number;
		FirstRun = false;

	} while (Number <= 0);

	return Number;
}

enPrim_NotPrime Check_Prime_Number(int Number)
{
	if (Number <= 1)
		return enPrim_NotPrime::Not_Prime;

	for (int Counter = 2; Counter <= Number / Counter; Counter++)
	{
		if (Number % Counter == 0)
			return enPrim_NotPrime::Not_Prime;
	}

	return enPrim_NotPrime::Prime;
}

void Print_Result(int Number)
{
	Clear_Screen();

	switch (Check_Prime_Number(Number))
	{
	case enPrim_NotPrime::Prime:
		cout << Number << " is Prime" << endl;
		break;
	case enPrim_NotPrime::Not_Prime:
		cout << Number << " Not Prime" << endl;
		break;
	}
}

int main()
{
	Print_Result(Get_Positive_Number());
	return 0;
}