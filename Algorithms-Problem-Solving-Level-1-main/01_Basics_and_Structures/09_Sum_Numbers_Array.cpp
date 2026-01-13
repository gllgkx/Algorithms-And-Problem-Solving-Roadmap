# include <iostream>
using namespace std;

void Read_Number(int Number[3])
{
	int i = 0;

	do
	{
		cout << "Please Enter Number " << i + 1 << endl;
		cin >> Number[i];

		i++;
	} while (i < 3);
}

int Calculate_Number(int Number[3])
{
	int Sum = 0;
	for (int i = 0; i < 3; i++)
	{
		Sum += Number[i];
	}
	return Sum;
}

void Print_Result(int Total)
{
	system("cls");
	cout << "Result : " << Total << endl;
}

int main()
{
	int Number[3];
	Read_Number(Number);
	Print_Result(Calculate_Number(Number));
	return 0;
}