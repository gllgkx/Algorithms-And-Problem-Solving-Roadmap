# include <iostream>
# include <string>
# include <ctime>
# include "MyLib.h" // Project-specific Library
using namespace std;

void Fill_Array_Randomly(int Arr[100], int Arr_Length)
{
	const short From = -100, To = 100;

	for (int i = 0; i < Arr_Length; i++)
	{
		Arr[i] = MyLib::Random_Number(From, To);
	}
}

int Count_Positive_Numbers(int Arr_Source[100], int Source_Length)
{
	int Counter{};

	for (int i = 0; i < Source_Length; i++)
	{
		if (Arr_Source[i] > 0)
		{
			Counter++;
		}
	}

	return Counter;
}

int Count_Negative_Numbers(int Arr_Source[100], int Source_Length)
{
	int Counter{};

	for (int i = 0; i < Source_Length; i++)
	{
		if (Arr_Source[i] < 0)
		{
			Counter++;
		}
	}

	return Counter;
}

int Get_Max_Number(int Arr_Source[100], int Source_Length)
{
	int Max_Number = Arr_Source[0];

	for (int i = 0; i < Source_Length; i++)
	{
		if (Arr_Source[i] > Max_Number)
		{
			Max_Number = Arr_Source[i];
		}
	}

	return Max_Number;
}

int Get_Sum_Number(int Arr_Source[100], int Source_Length)
{
	int Sum{};

	for (int i = 0; i < Source_Length; i++)
	{
		Sum += Arr_Source[i];
	}

	return Sum;
}

float Get_Array_Average(int Sum_Number, int Source_Length)
{
	return (float)Sum_Number / Source_Length;
}

void Print_Array(int Arr[100], int Array_Length)
{
	for (int i = 0; i < Array_Length; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

void Print_Result(const std::string& Text, float Number)
{
	cout << Text << Number << endl;
}

void Print_Full_Report(int Pos, int Neg, int Max, int Sum, float Avg)
{
	cout << "\n";

	cout << "--- Array Statistics ---\n";
	Print_Result("Positive Numbers Count : ", Pos);
	Print_Result("Negative Numbers Count : ", Neg);
	Print_Result("Max Numbers : ", Max);
	Print_Result("Sum of Numbers : ", Sum);
	Print_Result("Average : ", Avg);

	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Arr_Length{}, Target_Number{};
	int Positive_Numbers{}, Negative_Numbers{};
	int Max_Number{}, Sum_Number{};
	float Average_Number{};

	Arr_Length = MyLib::Read_Positive_Number("Enter Array Length: ");

	Fill_Array_Randomly(Arr, Arr_Length);
	Positive_Numbers = Count_Positive_Numbers(Arr, Arr_Length);
	Negative_Numbers = Count_Negative_Numbers(Arr, Arr_Length);
	Max_Number = Get_Max_Number(Arr, Arr_Length);
	Sum_Number = Get_Sum_Number(Arr, Arr_Length);
	Average_Number = Get_Array_Average(Sum_Number, Arr_Length);

	MyLib::Clear_Screen();

	cout << "Array Elements: " << Arr_Length << endl;
	Print_Array(Arr, Arr_Length);

	Print_Full_Report(Positive_Numbers, Negative_Numbers, Max_Number, Sum_Number, Average_Number);

	Target_Number = MyLib::Read_Number("Enter Number To Search For: ");

	short Index = MyLib::Find_Number_Position(Arr, Arr_Length, Target_Number);

	if (Index != -1)
		cout << "Number " << Target_Number << " Found at index: " << Index << endl;
	else
		cout << "Number " << Target_Number << " Not Found\n";

	return 0;
}