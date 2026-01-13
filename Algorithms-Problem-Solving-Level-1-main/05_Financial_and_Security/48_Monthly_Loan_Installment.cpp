# include <iostream>
# include <string>
# include "MyLib.h" // Project-specific Library
using namespace std;
using namespace MyLib;

struct stLoan_Information
{
	double Loan_Amount{};
	double Total_Months{};
};

stLoan_Information Read_Loan_Information()
{
	stLoan_Information info;

	info.Loan_Amount = Read_Positive_Number("Please enter a Loan Amount:");
	info.Total_Months = Read_Positive_Number("Please enter a Total Months:");

	return info;
}

double Calculate_Monthly_Installment(stLoan_Information const& info)
{
	return (info.Loan_Amount / info.Total_Months);
}

void Print_Result(stLoan_Information const& info)
{
	Clear_Screen();
	cout << "=====================\n";
	cout << "   Loan information  \n";
	cout << "=====================\n";
	cout << "Loan Amount = " << info.Loan_Amount << endl;
	cout << "Total Months = " << info.Total_Months << endl;
	cout << "Monthly Installment = " << Calculate_Monthly_Installment(info) << endl;
	cout << "=====================\n";
}

int main()
{
	Print_Result(Read_Loan_Information());
	return 0;
}