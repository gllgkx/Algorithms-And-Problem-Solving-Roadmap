#pragma once
# include <iostream>
# include <string>
using namespace std;

namespace MyLib
{
	void Clear_Screen() // This code clears the screen
	{
		cout << "\033[2J\033[1;1H";
	}

	double Read_Positive_Number(string Message)
	{
		double Value{};
		bool FirstRun = true;

		do
		{
			if (!FirstRun)
			{
				Clear_Screen();
				cout << "Wrong Input! Enter Number > 0\n";
			}

			cout << Message << endl;
			cin >> Value;
			FirstRun = false;

		} while (Value <= 0);

		return Value;
	}
}