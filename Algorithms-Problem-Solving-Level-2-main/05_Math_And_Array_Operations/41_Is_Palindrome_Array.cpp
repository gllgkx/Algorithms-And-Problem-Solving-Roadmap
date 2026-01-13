# include <iostream>
# include <string>
# include "MyLib.h" // Project-specific Library
using namespace std;

void Add_Array_Elements(int Number, int Arr[100], int& Arr_Length)
{
	Arr[Arr_Length] = Number;
	Arr_Length++;
}

void Input_User_Numbers(int Arr[100], int& Arr_Length)
{
	bool Add_More = true;

	do
	{
		int Number = MyLib::Read_Positive_Number("Please Enter a Number: ");

		Add_Array_Elements(Number, Arr, Arr_Length);

		cout << "Do you want to add more numbers? [0]No, [1]Yes?\n";
		cin >> Add_More;

	} while (Add_More);
}


bool Is_Palindrome_Array(int Arr_Source[100], int Source_Length)
{
	for (int i = 0; i < Source_Length / 2; i++)
	{
		if (Arr_Source[i] != Arr_Source[Source_Length - i - 1])
			return false;
	}
	return true;
}

void Print_Array(int Arr[100], int Arr_Length)
{
	for (int i = 0; i < Arr_Length; i++)
	{
		cout << Arr[i] << " ";
	}
}

int main()
{
	int Arr_1[100], Arr1_Length{};

	Input_User_Numbers(Arr_1, Arr1_Length);

	MyLib::Clear_Screen();

	cout << "Array 1 Elements: " << Arr1_Length << endl;
	Print_Array(Arr_1, Arr1_Length);

	if (Is_Palindrome_Array(Arr_1, Arr1_Length))
		cout << "\nYes array is Palindrome.\n";
	else
		cout << "\nNo array is Not Palindrome.\n";

	return 0;
}