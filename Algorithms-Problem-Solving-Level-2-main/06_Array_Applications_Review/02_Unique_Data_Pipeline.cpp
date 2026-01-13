# include <iostream>
# include <string>
# include <ctime>
# include "MyLib.h" // Project-specific Library
using namespace std;

void Input_User_Numbers(int Arr[100], int& Arr_Length)
{
	bool Add_More = true;

	do
	{
		int Number = MyLib::Read_Number("Please Enter a Number: ");

		MyLib::Add_Array_Elements(Number, Arr, Arr_Length);

		cout << "Do you want to add more numbers? [0]No, [1]Yes?: ";
		cin >> Add_More;

	} while (Add_More);
}

void Copy_Distinct_Numbers(int Arr_Source[100], int Arr_Dest[100], int Source_Length, int& Dest_Length)
{
	for (int i = 0; i < Source_Length; i++)
	{
		if (MyLib::Is_Number_In_Array(Arr_Dest, Dest_Length, Arr_Source[i]))
		{
			continue;
		}

		MyLib::Add_Array_Elements(Arr_Source[i], Arr_Dest, Dest_Length);
	}
}

void Copy_Array_In_Reverse(int Arr_Source[100], int Arr_Dest[100], int Source_Length, int& Dest_Length)
{
	for (int i = Source_Length - 1; i >= 0; i--)
	{
		MyLib::Add_Array_Elements(Arr_Source[i], Arr_Dest, Dest_Length);
	}
}

void Print_Array(int Arr[100], int Arr_Length)
{
	for (int i = 0; i < Arr_Length; i++)
	{
		cout << Arr[i] << " ";
	}

	cout << "\n";
}

void Print_Results(int Input_Array[100], int Distinct_Array[100], int Reversed_Array[100], int Arr1_Length, int Arr2_Length, int Arr3_Length)
{
	MyLib::Clear_Screen();

	cout << "--- Results --\n";
	cout << "User Input Array  : ";
	Print_Array(Input_Array, Arr1_Length);
	cout << "Distinct Array    : ";
	Print_Array(Distinct_Array, Arr2_Length);
	cout << "Reversed Distinct : ";
	Print_Array(Reversed_Array, Arr3_Length);
}

int main()
{
	int Input_Array[100], Distinct_Array[100], Reversed_Array[100];
	int Arr1_Length{}, Arr2_Length{}, Arr3_Length{};

	Input_User_Numbers(Input_Array, Arr1_Length);
	Copy_Distinct_Numbers(Input_Array, Distinct_Array, Arr1_Length, Arr2_Length);
	Copy_Array_In_Reverse(Distinct_Array, Reversed_Array, Arr2_Length, Arr3_Length);

	Print_Results(Input_Array, Distinct_Array, Reversed_Array, Arr1_Length, Arr2_Length, Arr3_Length);

	return 0;
}