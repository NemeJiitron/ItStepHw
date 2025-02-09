#pragma once
#include "IGameView.h"
class ConsoleGameView : public IGameView
{
private:
	int mistakes;
public:
	void DisplayWord(const std::string word) override
	{
		for (char letter : word)
		{
			if (letter == ' ')
			{
				std::cout << "_ ";
			}
			else {
				std::cout << letter << ' ';
			}
		}
		std::cout << std::endl;
	};
	void InitialMistakes(int mistakes) override
	{
		this->mistakes = mistakes;
		std::cout << "Mistakes: " << this->mistakes << std::endl;
	}

	void DisplayMistakes(int mistakes) override
	{
		std::cout << "Mistakes: " << mistakes << std::endl;
	};
	void WordGuessed() override
	{
		std::cout << "Word guessed!" << std::endl;
		system("pause");
	};
	void DisplayMessage(const std::string word) override
	{
		std::cout << "Display message\n";
	};
	
	void GuessedLetter(bool value) override
	{
		std::cout << "Letter guessed!" << std::endl;
	};
	
	void GameOver() override
	{
		std::cout << "Game over\n";
	};
	bool IsGameExit() override
	{
		char input;
		while (true)
		{
			std::cout << "Do you want to exit to main menu? (y/n): ";
			std::cin >> input;
			switch (input)
			{
			case 'y':
			case 'Y':
				return true;
				break;
			case 'n':
			case 'N':
				return false;
				break;
			default:
				system("cls");
					break;
			}
		}
	};
	char GetInputLetter() override
	{
		char input;
		std::cout << "Input letter: ";
		std::cin >> input;
		return input;
	};
};

