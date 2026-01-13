# include <iostream>
# include <string>
using namespace std;

const short SIZE = 3;
enum enPass_Fail {Pass = 1, Fail = 2};

void Read_Mark(float Marks[SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Please Enter Mark :" << i + 1 << endl;
		cin >> Marks[i];
	}
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
	return (Calculate_Sum(Marks) / SIZE);
}

enPass_Fail Check_Status(float Average)
{
	if (Average >= 50)
		return enPass_Fail::Pass;
	else
		return enPass_Fail::Fail;
}

void Print_Status(float Average)
{
	cout << "Your Average is: " << Average << endl;

	if (Check_Status(Average) == enPass_Fail::Pass)
		cout << "You : Pass" << endl;
	else
		cout << "You : Fail" << endl;
}

int main()
{
	float Marks[SIZE];
	Read_Mark(Marks);

	system("cls"); // This code will erase everything that came before from the screen
	Print_Status(Calculate_Average(Marks));
	return 0;
}