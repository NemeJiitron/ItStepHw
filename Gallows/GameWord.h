#pragma once
#include <iostream>
#include <string>
#include <algorithm>

class GameWord
{
private:
	std::string hidden_word;
	std::string external_word;
public:
	GameWord(std::string& word)
		:hidden_word(word)
	{
		external_word.insert(0, word.length(), ' ');
	}
	bool inputLetter(char letter)
	{
		bool flag = false;
		for (size_t i = 0; i < hidden_word.size(); i++)
		{
			if (hidden_word[i] == letter)
			{
				external_word[i] = letter;
				flag = true;
			}
		}
		return flag;
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

