# include <iostream>
# include <string>
using namespace std;

float Get_Number_Input()
{
	float Number = 0;
	cout << "Please Enter Number\n";
	cin >> Number;
	return Number;
}

float Get_Half_Number(float Number)
{
	float half = 0;
	half += Number / 2;
	return half;
}

void Print_Half_Number(float Number)
{
	system("cls");
	string Result = "Half of " + to_string(Number) + " is " + to_string(Get_Half_Number(Number));
	cout << Result << endl;
}

int main()
{
	Print_Half_Number(Get_Number_Input());
	return 0;
}