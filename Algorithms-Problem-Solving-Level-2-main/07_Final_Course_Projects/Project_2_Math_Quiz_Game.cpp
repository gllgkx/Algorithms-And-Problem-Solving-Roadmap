# include <iostream>
# include <string>
# include <ctime>
# include "MyLib.h" // Project-specific Library
using namespace std;

enum enLevel { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Subtract = 2, Multiply = 3, Division = 4, MixOp = 5 };

struct stQuestion
{
	int Number_1{};
	int Number_2{};
	enLevel Question_Level;
	enOperationType Operation_Type;
	short Correct_Answer{};
	short Player_Answer{};
	bool Answer_Result = false;
};

struct stQuizz
{
	stQuestion Question_List[100];
	short Number_Of_Question{};
	enLevel Questions_Level;
	enOperationType OpType;
	short Number_Of_Rigth_Answer{};
	short Number_Of_Wrong_Answer{};
	bool isPass = false;
};

int Get_Random_Number(enLevel Level)
{
	switch (Level)
	{
	case enLevel::Easy: return MyLib::Random_Number(1, 10);
	case enLevel::Medium: return MyLib::Random_Number(10, 50);
	case enLevel::Hard: return MyLib::Random_Number(50, 100);
	default: return MyLib::Random_Number(1, 10);
	}
}

enOperationType Get_Random_Operation_Type()
{
	return (enOperationType)MyLib::Random_Number(1, 4);
}

string Get_Op_Symbol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add: return "+";
	case enOperationType::Subtract: return "-";
	case enOperationType::Multiply: return "*";
	case enOperationType::Division: return "/";

	default: return "Mix";
	}
}

string Get_Question_Level_Text(enLevel Level)
{
	string Arr_Level_Text[4] = { "Easy","Medium","Hard","Mix" };
	return Arr_Level_Text[Level - 1];
}

int Calculator(int Number_1, int Number_2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return (Number_1 + Number_2);
	case enOperationType::Subtract:
		return (Number_1 - Number_2);
	case enOperationType::Multiply:
		return (Number_1 * Number_2);
	case enOperationType::Division:
		return (Number_1 / Number_2);

	default: return (Number_1 + Number_2);
	}
}

stQuestion Generate_Question(enLevel Question_Level, enOperationType OpType)
{
	stQuestion Question;

	if (Question_Level == enLevel::Mix)
		Question_Level = (enLevel)MyLib::Random_Number(1, 3);

	if (OpType == enOperationType::MixOp)
		OpType = Get_Random_Operation_Type();

	Question.Operation_Type = OpType;

	if (OpType == enOperationType::Division)
	{
		Question.Number_2 = Get_Random_Number(Question_Level);
		int Simple_Result = Get_Random_Number(Question_Level);
		Question.Number_1 = Question.Number_2 * Simple_Result;
	}
	else
	{
		Question.Number_1 = Get_Random_Number(Question_Level);
		Question.Number_2 = Get_Random_Number(Question_Level);
	}

	Question.Correct_Answer = Calculator(Question.Number_1, Question.Number_2, Question.Operation_Type);
	Question.Question_Level = Question_Level;

	return Question;
}

void Print_Question(stQuestion Question, short Question_Number, short Number_Of_Questions)
{
	cout << "Question [" << Question_Number << "/" << Number_Of_Questions << "] \n\n";
	cout << Question.Number_1 << endl;
	cout << Question.Number_2 << " " << Get_Op_Symbol(Question.Operation_Type) << endl;
	cout << string(12, '-') << endl;
}

void Correct_The_Question_Answer(stQuizz& Quizz, short Question_Number)
{
	if (Quizz.Question_List[Question_Number].Player_Answer != Quizz.Question_List[Question_Number].Correct_Answer)
	{
		Quizz.Question_List[Question_Number].Answer_Result = false;
		Quizz.Number_Of_Wrong_Answer++;

		cout << "Wrong Answer :-( \n";
		cout << "The Right answer is: " << Quizz.Question_List[Question_Number].Correct_Answer << endl;
		cout << "\a";

		system("color 4F");
	}
	else
	{
		Quizz.Question_List[Question_Number].Answer_Result = true;
		Quizz.Number_Of_Rigth_Answer++;

		cout << "Right Answer :-) \n";

		system("color 2F");
	}
	cout << endl;
}

void Ask_And_Correct_Question_List_Answer(stQuizz& Quizz)
{
	for (short Question_Number = 0; Question_Number < Quizz.Number_Of_Question; Question_Number++)
	{
		Quizz.Question_List[Question_Number] = Generate_Question(Quizz.Questions_Level, Quizz.OpType);

		Print_Question(Quizz.Question_List[Question_Number], Question_Number + 1, Quizz.Number_Of_Question);

		cin >> Quizz.Question_List[Question_Number].Player_Answer;

		Correct_The_Question_Answer(Quizz, Question_Number);

		system("pause");
		MyLib::Clear_Screen();
	}
	Quizz.isPass = (Quizz.Number_Of_Rigth_Answer > Quizz.Number_Of_Wrong_Answer);
}

void Print_Quizz_Results(stQuizz Quizz)
{
	system("color 07");

	cout << string(40, '-') << endl;
	cout << " Final Result is " << (Quizz.isPass ? "Pass :-)" : "Fail :-(") << endl;
	cout << string(40, '-') << endl;
	cout << "Number Of Question: " << Quizz.Number_Of_Question << endl;
	cout << "Question Level    : " << Get_Question_Level_Text(Quizz.Questions_Level) << endl;
	cout << "Question Type     : " << Get_Op_Symbol(Quizz.OpType) << endl;
	cout << "Number Of Rigth Answer: " << Quizz.Number_Of_Rigth_Answer << endl;
	cout << "Number Of Wrong Answer: " << Quizz.Number_Of_Wrong_Answer << endl;
	cout << string(40, '-') << endl;
}

void Play_Math()
{
	stQuizz Quizz;

	Quizz.Number_Of_Question = MyLib::Read_Positive_Number("How many Question Do you want: ");
	Quizz.Questions_Level = (enLevel)MyLib::Read_Number("Enter Level [1]Easy, [2]Med, [3]Hard, [4]Mix : ");
	Quizz.OpType = (enOperationType)MyLib::Read_Number("Enter OpType [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix : ");

	MyLib::Clear_Screen();

	Ask_And_Correct_Question_List_Answer(Quizz);
	Print_Quizz_Results(Quizz);
}

void Start_Game()
{
	char PlayAgain = 'Y';
	do
	{
		MyLib::Clear_Screen();
		Play_Math();

		cout << endl << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

		if (PlayAgain == 'N' || PlayAgain == 'n')
		{
			system("color 07");
			MyLib::Clear_Screen();
			cout << "Good Bye." << endl;
		}

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	Start_Game();
	return 0;
}