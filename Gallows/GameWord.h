#pragma once
#include <iostream>

class GameWord
{
private:
	std::string hidden_word;
	std::string external_word;
public:
	GameWord(std::string& word)
		:hidden_word(word), external_word(word)
	{}
	bool inputLetter(char ch)
	{
		return false;

		hidden_word.find(ch);
	}
	std::string& getExtrWord()
	{
		return external_word;
	}
	bool isGuessed() const
	{
		return hidden_word == external_word;
	}
};

