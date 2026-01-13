# include <iostream>
# include <string>
# include <ctime>
# include "MyLib.h" // Project-specific Library
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner{Player = 1,Computer = 2,Draw = 3};

struct stRoundInfo
{
	enGameChoice PlayerChoice{};
	enGameChoice ComputerChoice{};
	enWinner Winner;
	string WinnerName = " ";
	short Round_Number{};
};

struct stGameResults
{
	short PlayerWinCount{};
	short ComputerWinCount{};
	short Draw_Round{};
	short GameRounds;
	enWinner GameWinner;
	string GameWinnerName = " ";
	stRoundInfo Round;
};

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
	return arrGameChoices[Choice - 1];
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player","Computer","No Winner (Draw)" };
	return arrWinnerName[Winner - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player: system("color 2F"); break;
	case enWinner::Computer: cout << "\a"; system("color 4F"); break;
	default: system("color 6F"); break;
	}
}

enWinner WhoWonRound(stRoundInfo const& RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	else if (RoundInfo.PlayerChoice == enGameChoice::Stone && RoundInfo.ComputerChoice == enGameChoice::Scissors ||
		RoundInfo.PlayerChoice == enGameChoice::Paper && RoundInfo.ComputerChoice == enGameChoice::Stone ||
		RoundInfo.PlayerChoice == enGameChoice::Scissors && RoundInfo.ComputerChoice == enGameChoice::Paper)
	{
		return enWinner::Player;
	}

	else
	{
		return enWinner::Computer;
	}
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	MyLib::Clear_Screen();

	SetWinnerScreenColor(RoundInfo.Winner);

	cout << "-------------- Round [" << RoundInfo.Round_Number << "] --------------\n";
	cout << "Player   Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : " << RoundInfo.WinnerName << endl;
	cout << "---------------------------------------\n";
}

enWinner WhoWonGame(short PlayerWinCount, short ComputerWinCount)
{
	if (PlayerWinCount > ComputerWinCount)
		return enWinner::Player;
	else if (ComputerWinCount > PlayerWinCount)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResults FillGameResult(stRoundInfo RoundInfo, short HowManyRounds, short DrawRound, short PlayerWinCount, short ComputerWinCount)
{
	stGameResults Result;

	Result.GameRounds = HowManyRounds;
	Result.PlayerWinCount = PlayerWinCount;
	Result.ComputerWinCount = ComputerWinCount;
	Result.Draw_Round = DrawRound;
	Result.GameWinner = WhoWonGame(PlayerWinCount, ComputerWinCount);
	Result.GameWinnerName = WinnerName(Result.GameWinner);

	return Result;
}

enGameChoice ReadPlayerChoice()
{
	short Number{};
	bool FirstRun = true;

	do
	{
		if (!FirstRun)
		{
			cout << "Wrong Number! Please Enter Number From 1 To 3.\n";
		}

		cout << "Please Enter Choice: ";
		cout << " [1] Stone" << " [2] Paper" << " [3] Scissor\n";
		cin >> Number;

		FirstRun = false;

	} while (Number < 1 || Number > 3);

	return (enGameChoice)Number;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)MyLib::Random_Number(1, 3);
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short DrawRound{}, PlayerWinCount{}, ComputerWinCount{};

	for (int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();

		RoundInfo.Round_Number = GameRound;
		RoundInfo.Winner = WhoWonRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
		

		if (RoundInfo.Winner == enWinner::Draw)
			DrawRound++;
		else if (RoundInfo.Winner == enWinner::Player)
			PlayerWinCount++;
		else
			ComputerWinCount++;

		PrintRoundResults(RoundInfo);
		cout << "\n";
	}

	system("pause");
	MyLib::Clear_Screen();

	return FillGameResult(RoundInfo,HowManyRounds,DrawRound,PlayerWinCount,ComputerWinCount);
}

string Tabs(short NumberOfTabs)
{
	string t = "";

	for (int i = 1; i < NumberOfTabs; i++)
	{
		t += "\t";
	}
	return t;
}

void ShowGameOverScreen()
{
	MyLib::Clear_Screen();

	cout << Tabs(3) << string(60, '-') << endl;
	cout << "\t\t\t\t\t\t\t       +++ Game Over +++" << Tabs(2) << endl;
	cout << Tabs(3) << string(60, '-') << endl;
}

void ShowFinalGameOverScreen(stGameResults const& Result)
{
	cout << Tabs(3) << string(24, '-') << " [Game Results] " << string(20, '-') << endl;
	cout << Tabs(3) << "Game Rounds        : " << Result.GameRounds << endl;
	cout << Tabs(3) << "Player won times   : " << Result.PlayerWinCount << endl;
	cout << Tabs(3) << "Computer won times : " << Result.ComputerWinCount << endl;
	cout << Tabs(3) << "Draw times         : " << Result.Draw_Round << endl;
	cout << Tabs(3) << "Final Winner       : " << Result.GameWinnerName << endl;

	cout << Tabs(3) << string(60, '-') << endl;

	SetWinnerScreenColor(Result.GameWinner);
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		short HowManyRounds = MyLib::Read_Number("How many round : ");
		stGameResults GameResults = PlayGame(HowManyRounds);

		ShowGameOverScreen();
		ShowFinalGameOverScreen(GameResults);


		cout << Tabs(3) << "Do you want to play again? (Y/N) \n";
		cin >> PlayAgain;

		if (PlayAgain == 'y' || PlayAgain == 'Y')
		{
			MyLib::Clear_Screen();
			system("color 07");
		}
		else if (PlayAgain == 'n' || PlayAgain == 'N')
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
	
	StartGame();

	return 0;
}