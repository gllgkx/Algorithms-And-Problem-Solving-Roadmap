# include <iostream>
using namespace std;

struct stName
{
	string first_name, last_name;
	bool reversed;
};

stName Get_Name_Input()
{
	stName info;

	cout << "Please Enter First Name:" << endl;
	cin >> info.first_name;
	cout << "Please Enter Last Name:" << endl;
	cin >> info.last_name;
	cout << "Full Name Reversed?" << endl;
	cin >> info.reversed;

	return info;
}

string Get_Full_Name(stName info)
{
	string full_Name;
	if (info.reversed)
		full_Name = info.last_name + " " + info.first_name;
	else
		full_Name = info.first_name + " " + info.last_name;
	return full_Name;
}

void PrintName(string full_name)
{
	system("cls");
	cout << "\n Your full name is: " << full_name << endl;
}

int main()
{
	PrintName(Get_Full_Name(Get_Name_Input()));
	return 0;
}