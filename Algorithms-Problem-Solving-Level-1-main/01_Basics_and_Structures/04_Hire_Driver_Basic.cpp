# include <iostream>
# include <string>
using namespace std;

struct stUser_Information
{
	short Age = 0;
	bool HasDrivingLicense;
};

stUser_Information Read_Information()
{
	stUser_Information info;
	cout << "Please Enter Age\n";
	cin >> info.Age;
	cout << "Do You Have A Driver License (Yes = 1, No = 0)\n";
	cin >> info.HasDrivingLicense;
	return info;
}

bool Check_Information(stUser_Information info)
{
	return (info.Age >= 21 && info.HasDrivingLicense == true);
}

void PrintResult(stUser_Information info)
{
	if (Check_Information(info))
	{
		cout << "\nYou are Hired\n";
	}
	else
	{
		cout << "\nYou Are is Rejected\n";
	}
}


int main()
{
	PrintResult(Read_Information());
	return 0;
}