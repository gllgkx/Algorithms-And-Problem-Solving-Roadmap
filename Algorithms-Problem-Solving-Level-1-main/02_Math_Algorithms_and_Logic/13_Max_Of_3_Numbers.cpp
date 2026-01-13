# include <iostream>
using namespace std;

struct stNumber
{
	float Num_1 = 0;
	float Num_2 = 0;
	float Num_3 = 0;
};

stNumber Get_User_Input()
{
	stNumber info;
	cout << "Please Enter Number 1:\n";
	cin >> info.Num_1;
	cout << "Please Entre Number 2:\n";
	cin >> info.Num_2;
	cout << "Please Entre Number 3:\n";
	cin >> info.Num_3;
	return info;
}

float Check_Max_Number(stNumber info)
{
	float Max_Number = 0;
	if (info.Num_1 > info.Num_2)
		if (info.Num_1 > info.Num_3)
			Max_Number = info.Num_1;
		else
			Max_Number = info.Num_3;
	else
	{
		if (info.Num_2 > info.Num_3)
			Max_Number = info.Num_2;
		else
			Max_Number = info.Num_3;
	}
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