# include <iostream>
using namespace std;

const short SIZE = 3;

void Read_Marks(float Marks[SIZE])
{
	int i = 0;

	do
	{
		cout << "Please Enter Mark? " << i + 1 << endl;
		cin >> Marks[i];

		i++;
	} while (i < SIZE);
}

float Calculate_Sum(float Marks[SIZE])
{
	float Sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		Sum += Marks[i];
	}
	return Sum;
}

float Calculate_Average(float Marks[SIZE])
{
	return Calculate_Sum(Marks) / SIZE;
}

void Print_Average(float Average)
{
	system("cls");
	cout << "Average is : " << Average << endl;
}

int main()
{
	float Marks[SIZE];
	Read_Marks(Marks);
	Print_Average(Calculate_Average(Marks));
	return 0;
}