# include <iostream>
using namespace std;

struct stNumber
{
	float Num_one = 0;
	float Num_two = 0;
};

stNumber Get_User_Input()
{
	stNumber info;
	cout << "Please Enter First Number:\n";
	cin >> info.Num_one;
	cout << "Please Entre Second Number:\n";
	cin >> info.Num_two;
	return info;
}

float Check_Max_Number(stNumber info)
{
	float Max_Number = 0;
	if (info.Num_one > info.Num_two)
		Max_Number = info.Num_one;
	else
		Max_Number = info.Num_two;
	return Max_Number;
}

void Print_Max_Number(stNumber info)
{
	system("cls"); // This code will erase everything that came before from the screen
	cout << "Max Number is : " << Check_Max_Number(info) << endl;
}

int main()
{
	Print_Max_Number(Get_User_Input());
	return 0;
}