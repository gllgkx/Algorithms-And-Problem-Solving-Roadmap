# include <iostream>
using namespace std;

enum enPassFail {Pass = 1, Fail = 2};

float Read_Grade_Info()
{
	float Mark = 0;
	cout << "Please Enter Grade:\n";
	cin >> Mark;
	return Mark;
}

enPassFail Check_Mark(float Mark)
{
	if (Mark >= 50 )
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void Print_Info(float Mark)
{
	system("cls");
	if (Check_Mark(Mark) == enPassFail::Pass)
		cout << "You Pass" << endl;
	else
		cout << "You Fail" << endl;
}

int main()
{
	Print_Info(Read_Grade_Info());
	return 0;
}