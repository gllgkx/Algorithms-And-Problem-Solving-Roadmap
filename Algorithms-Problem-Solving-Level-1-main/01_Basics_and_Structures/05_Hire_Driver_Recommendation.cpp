# include <iostream>
# include <string>
using namespace std;

struct stUser_Information
{
	short Age = 0;
	bool HasDrivingLicense;
	bool HasRecommendation;
};

stUser_Information Read_Information()
{
	stUser_Information info;
	cout << "Please Enter Age\n";
	cin >> info.Age;
	cout << "Do you have a driver's License (Yes = 1, No = 0)\n";
	cin >> info.HasDrivingLicense;
	cout << "Do you have a Recommendation (Yes = 1, No = 0)\n";
	cin >> info.HasRecommendation;
	return info;
}

bool Check_Information(stUser_Information info)
{
	return (info.Age >= 21 && info.HasDrivingLicense || info.HasRecommendation);
}

void PrintResult(stUser_Information info)
{
	system("cls");
	if (Check_Information(info))
	{
		cout << "Hired\n";
	}
	else
	{
		cout << "Rejected\n";
	}
}


int main()
{
	PrintResult(Read_Information());
	return 0;
}