# include <iostream>
# include <string>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

double Read_Total_Sales()
{
	double Total_Sales{};
	cout << "Please enter a total sales\n";
	cin >> Total_Sales;
	return Total_Sales;
}

float Get_Commission_Percentage(double Total_Sales)
{
	if (Total_Sales >= 1000000)
		return 0.01;
	else if (Total_Sales >= 500000)
		return 0.02;
	else if (Total_Sales >= 100000)
		return 0.03;
	else if (Total_Sales >= 50000)
		return 0.05;
	else
		return 0.00;
}

float Calculate_Total_Commission(double Total_Sales, float Commission)
{
	return Total_Sales * Commission;
}

void Print_info(double Total_Sales)
{
	float Commission = Get_Commission_Percentage(Total_Sales);
	Clear_Screen();
	cout << "============================\n";
	cout << "      Sales information     \n";
	cout << "============================\n";
	cout << "Total Sales      : " << Total_Sales << endl;
	cout << "Commission Rate  : " << (Commission * 100) << "%" << endl;
	cout << "Total Commission : " << Calculate_Total_Commission(Total_Sales, Commission) << endl;
	cout << "============================\n";
}

int main()
{
	Print_info(Read_Total_Sales());
	return 0;

}
