# include <iostream>
# include <string>
# include <ctime>
# include "MyLib.h" // Project-specific Library
using namespace std;

void Fill_Array_With_Random_Number(int Arr[100], int Arr_Length)
{
	const short From = 1, To = 100;

	for (int i = 0; i < Arr_Length; i++)
	{
		Arr[i] = MyLib::Random_Number(From, To);
	}
}

int Count_Even_Number(int Arr_Source[100], int Source_Length)
{
	int Counter{};

	for (int i = 0; i < Source_Length; i++)
	{
		if (Arr_Source[i] % 2 == 0)
		{
			Counter++;
		}
	}

	return Counter;
}

void Print_Array(int Arr[100], int Array_Length)
{
	for (int i = 0; i < Array_Length; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Arr[100], Arr_Length{};

	Arr_Length = MyLib::Read_Positive_Number("Please Enter Number ?");
	Fill_Array_With_Random_Number(Arr, Arr_Length);

	MyLib::Clear_Screen();

	cout << "Array Elements: " << Arr_Length << endl;
	Print_Array(Arr, Arr_Length);

	cout << "\nEven Number In Array: " << Count_Even_Number(Arr, Arr_Length) << endl;

	return 0;
}