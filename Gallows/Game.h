#pragma once
#include "GameWordsBuilder.h"
#include <memory>

class Game
{
private:
	std::unique_ptr<GameWord> current_word;
	int mistakes;
	GameWordsBuilder words_builder;
public:
	Game(const std::shared_ptr<WordsManager> words)
		:words_builder(words)
	{ 
		mistakes = 6;
	}
	void Start()
	{
		while (!current_word->isGuessed() && mistakes < 6)
		{
			current_word = std::make_unique<GameWord>(words_builder.getRandomWord());
			char n;
			std::cout << "Input letter: ";
			std::cin >> n;
			if (current_word->inputLetter(n))
			{
				std::cout << "Guessed!";
			}
			else
			{
				std::cout << "Not Guessed!";
				mistakes++;
			}

		}
	}
	void End()
	{

	}
	void Save() {}
	void Load() {}
	~Game();
};

