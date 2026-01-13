# include <iostream>
# include <string>
# include "MyLib.h" // Project-specific Library
using namespace std;
using namespace MyLib;

struct stLoan_Information
{
	double Loan_Amount{};
	double Monthly_Installment{};
};

stLoan_Information Read_Loan_Information()
{
	stLoan_Information info;

	info.Loan_Amount = Read_Positive_Number("Please enter a Loan Amount:");
	info.Monthly_Installment = Read_Positive_Number("Please enter a Monthly Installment");

	return info;
}

double Calculate_Loan_Duration(stLoan_Information const& info)
{
	return (info.Loan_Amount / info.Monthly_Installment);
}

void Print_Result(stLoan_Information const& info)
{
	Clear_Screen();
	cout << "=====================\n";
	cout << "   Loan information  \n";
	cout << "=====================\n";
	cout << "Loan Amount = " << info.Loan_Amount << endl;
	cout << "Monthly Installment = " << info.Monthly_Installment << endl;
	cout << "Total Months = " << Calculate_Loan_Duration(info) << endl;
	cout << "=====================\n";
}

int main()
{
	Print_Result(Read_Loan_Information());
	return 0;
}