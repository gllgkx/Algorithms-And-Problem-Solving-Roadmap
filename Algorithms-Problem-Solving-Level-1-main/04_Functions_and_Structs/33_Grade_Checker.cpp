# include <iostream>
# include <string>
using namespace std;

void Clear_Screen()
{
	cout << "\033[2J\033[1;1H";
}

float Read_Grade(const int &From,const int &To)
{
	float Grade{};
	do
	{
		cout << "Please enter a Grade between 0 and 100?\n";
		cin >> Grade;
	} while (Grade < From || Grade > To);
	return Grade;
}

char Check_Grade(float Grade)
{
	if (Grade >= 90)
		return 'A';
	else if (Grade >= 80)
		return 'B';
	else if (Grade >= 70)
		return 'C';
	else if (Grade >= 60)
		return 'D';
	else if (Grade >= 50)
		return 'E';
	else
		return 'F';
}

void Print_info(float Grade)
{
	Clear_Screen();
	cout << "Grade is " << Check_Grade(Grade) << endl;
}

int main()
{
	int From = 0, To = 100;
	Print_info(Read_Grade(From,To));
	return 0;

}
