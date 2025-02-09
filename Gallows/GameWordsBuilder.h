#pragma once
#include "WordsManager.h"
#include "GameWord.h"

class GameWordsBuilder
{
private:
	std::vector<std::string> buffer;
	std::shared_ptr<WordsManager> manager;
public:
	GameWordsBuilder(const std::shared_ptr<WordsManager>& manager)
		:manager(manager)
	{
		buffer = manager->GetWords();
	}
	GameWord getRandomWord()
	{
		int i = rand() % buffer.size();
		buffer.erase(buffer.begin() + i);
		return buffer[i];
	}
	void Show()
	{
		for (size_t i = 0; i < buffer.size(); i++)
		{
			std::cout << buffer[i];
		}
	}
};
