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
		auto&& first = buffer.begin();
		GameWord result(*first);
		buffer.erase(first);
		return result;
	}
};

