# include <iostream>
# include <string>
# include <ctime>
# include "MyLib.h" // Project-specific Library
using namespace std;

void Swap_Number (int& A, int& B)
{
	int Tamp = A;
	A = B;
	B = Tamp;
}

void Fill_Array_With_Random_Numbers(int Arr[100], int& Arr_Length)
{
	const short From = 1, To = 50;

	for (int i = 0; i < Arr_Length; i++)
	{
		Arr[i] = MyLib::Random_Number(From, To);
	}
}

void Copy_Prime_Numbers(int Arr_Source[100],int Arr_Dest[100],int Source_Length,int& Dest_Length)
{
	for (int i = 0; i < Source_Length; i++)
	{
		if (MyLib::Is_Prime_Number(Arr_Source[i]))
		{
			MyLib::Add_Array_Elements(Arr_Source[i], Arr_Dest, Dest_Length);
		}
	}
}

bool Is_Palindrome_Array(int Arr_Source[100], int Source_Length)
{
	for (int i = 0; i < Source_Length; i++)
	{
		if (Arr_Source[i] != Arr_Source[Source_Length - i - 1])
		{
			return false;
		}
	}

	return true;
}

void Shuffle_Array(int Arr[100], int Arr_Length)
{
	const short From = 0, To = Arr_Length - 1;

	for (int i = 0; i < Arr_Length; i++)
	{
		int Random_Index = MyLib::Random_Number(From, To);

		Swap_Number(Arr[i], Arr[Random_Index]);
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

void Print_Full_Report(int Arr1[100], int Arr2[100], int Arr1_Length, int& Arr2_Length)
{
	MyLib::Clear_Screen();

	cout << "Array 1 (Random):\n";
	Print_Array(Arr1, Arr1_Length);
	cout << "\nArray 2 (Primes Only):\n";
	Print_Array(Arr2, Arr2_Length);

	cout << "\nIs Prime Array Palindrome?\n";
	if (Is_Palindrome_Array(Arr2, Arr2_Length))
		cout << "Yes.\n";
	else
		cout << "No.\n";

	Shuffle_Array(Arr2, Arr2_Length);
	cout << "\nArray 2 After Shuffle:\n";
	Print_Array(Arr2, Arr2_Length);
}

int main()
{
	int Arr1[100], Arr2[100];
	int Arr1_Length{}, Arr2_Length{};

	Arr1_Length = MyLib::Read_Positive_Number("Enter Number Of Elements: ");

	Fill_Array_With_Random_Numbers(Arr1, Arr1_Length);
	Copy_Prime_Numbers(Arr1, Arr2, Arr1_Length, Arr2_Length);

	Print_Full_Report(Arr1, Arr2, Arr1_Length, Arr2_Length);

	return 0;
}