#pragma once
#include "GameWordsBuilder.h"
#include <memory>
#include "IGameView.h"

class Game
{
private:
	std::unique_ptr<GameWord> current_word;
	int mistakes;
	GameWordsBuilder words_builder;
	std::unique_ptr<IGameView> view;
	const int max_mistakes = 6;
public:
	Game(std::shared_ptr<WordsManager> manager, std::unique_ptr<IGameView> view)
		:words_builder(manager), view(std::move(view))
	{ 
		mistakes = 0;
	}
	void Start()
	{
		

		do
		{
			current_word = std::make_unique<GameWord>(words_builder.getRandomWord());
			view->DisplayWord(current_word->getExtrWord());
			view->DisplayMistakes(mistakes);
			while (!current_word->isGuessed() && mistakes < max_mistakes) {
				char letter = view->GetInputLetter();
				if (current_word->inputLetter(letter))
				{
					view->DisplayWord(current_word->getExtrWord());
				}
				else
				{
					++mistakes;
				}
				view->DisplayMistakes(mistakes);

			}
			
			
			if (mistakes < max_mistakes)
			{
				view->WordGuessed();
			}
			else {
				view->GameOver();
				break;
			}
			current_word = std::make_unique<GameWord>(words_builder.getRandomWord());
		} while (!view->IsGameExit());
	}
	void End()
	{

	}
	void Save() {}
	void Load() {}
	~Game()
	{
	};
};

