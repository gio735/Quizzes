#include <string>
#include <iostream>
#pragma once
class TicTacToe
{
public:
	char Table[3][3];
	std::string PlayerXName;
	std::string PlayerOName;
	TicTacToe(std::string playerXName, std::string playerOName)
	{
		PlayerOName = playerOName;
		PlayerXName = playerXName;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Table[i][j] = ' ';
			}
		}
		ClassicGame();
	}
private:
	void ClassicGame()
	{
		std::pair<bool, bool> result = std::make_pair(false, false);//xWon and oWon
		while (true)
		{
			system("CLS");
			DrawTable();
			std::cout << "X's turn:\n";
			ChoosePlacement('X');
			ClassicVictoryCheck(result.first, result.second);
			if (result.first || result.second) break;
			system("CLS");
			DrawTable();
			std::cout << "O's turn:\n";
			ChoosePlacement('O');
			ClassicVictoryCheck(result.first, result.second);
			if (result.first || result.second) break;
		}
		system("CLS");
		DrawTable();
		if (result.first)
		{
			std::cout << "Let's congratulate to warrior " << PlayerXName << " for great match!\n";
		}
		else if (result.second)
		{
			std::cout << "Let's congratulate to warrior " << PlayerOName << " for great match!\n";
		}
		else
		{
			std::cout << "Seems like it's a draw... What else to expect from two powerful player!";
		}
	}

	void ClassicVictoryCheck(bool& xWon, bool& oWon)//in return type, first bool represents victory of player X second represents victory of O
	{
		char lastSlot;
		for (int i = 0; i < 3; i++)
		{
			lastSlot = Table[i][0];
			bool skipped = false;
			for (int j = 1; j < 3; j++)
			{
				if (Table[i][j] != lastSlot)
				{
					skipped = true;
					break;
				}
			}
			if (!skipped)
			{
				if (lastSlot == 'X')
					xWon = true;
				else if (lastSlot == 'O')
					oWon = true;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			lastSlot = Table[0][i];
			bool skipped = false;
			for (int j = 1; j < 3; j++)
			{
				if (Table[j][i] != lastSlot)
				{
					skipped = true;
					break;
				}
			}
			if (!skipped)
			{
				if (lastSlot == 'X')
					xWon = true;
				else if (lastSlot == 'O')
					oWon = true;
			}
		}
		if (Table[0][0] == Table[1][1] && Table[0][0] == Table[2][2])
		{
			if (Table[1][1] == 'X')
				xWon = true;
			else if (Table[1][1] == 'O')
				oWon = true;
		}
		if (Table[2][0] == Table[1][1] && Table[2][0] == Table[0][2])
		{
			if (Table[1][1] == 'X')
				xWon = true;
			else if (Table[1][1] == 'O')
				oWon = true;
		}
	}
	void DrawTable()
	{
		int size = 3;
		std::cout << "   | ";
		for (int i = 1; i <= size; i++)
		{
			std::cout << i << " | ";
		}
		int lineSize = 3 + 2;
		std::cout << "\n";

		for (int i = 1; i <= size; i++)
		{
			std::cout << "-------------------" << "\n";
			std::cout << " " << i << " | ";

			for (int j = 0; j < size; j++)
			{
				switch (Table[i - 1][j])
				{
				case 'X':
					std::cout << "X | ";
					break;
				case 'O':
					std::cout << "O | ";
					break;
				default:
					std::cout << "  | ";
					break;
				}

			}
			std::cout << "\n";
		}
		std::cout << "-------------------" << "\n";
	}
	void ChoosePlacement(char user)
	{
		bool takingChoice = true;
		while (takingChoice)
		{
			std::cout << "Give X coordinate (top side numbers): ";
			int xCoordinate, yCoordinate;
			std::cin >> xCoordinate;
			std::cout << "Give Y coordinate (left side numbers): ";
			std::cin >> yCoordinate;
			if (xCoordinate > 3 || yCoordinate > 3 || yCoordinate < 1 || xCoordinate < 1)
			{
				continue;
			}
			if (Table[yCoordinate - 1][xCoordinate - 1] != ' ') continue;
			Table[yCoordinate - 1][xCoordinate - 1] = user;
			takingChoice = false;
		}

	}
};

