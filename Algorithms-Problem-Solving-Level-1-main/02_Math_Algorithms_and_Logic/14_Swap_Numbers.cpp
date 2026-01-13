# include <iostream>
using namespace std;

void Read_Number_info(int& Num_1, int& Num_2)
{
	cout << "Please Enter First Number ?\n";
	cin >> Num_1;
	cout << "Please Enter Second Number ?\n";
	cin >> Num_2;
}

void Swap_Number(int& Num_1, int& Num_2)
{
	int Tamp = 0;
	Tamp = Num_1;
	Num_1 = Num_2;
	Num_2 = Tamp;
}

void Print_Number(int Num_1, int Num_2)
{
	cout << "Number 1 = " << Num_1 << endl;
	cout << "Number 2 = " << Num_2 << endl;
}

int main()
{
	int Num_1 = 0, Num_2 = 0;
	Read_Number_info(Num_1, Num_2);

	system("cls"); // This code will erase everything that came before from the screen
	Print_Number(Num_1, Num_2);
	Swap_Number(Num_1, Num_2);
	Print_Number(Num_1, Num_2);
	return 0;
}