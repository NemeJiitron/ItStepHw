#pragma once
#include <iostream>
#include <vector>
#include <string>

class WordsManager
{
private:
	std::vector<std::string> words;
public:
	const std::vector<std::string>& GetWords() const
	{
		return words;
	}
	void Save() {}
	void Load() {}
	void Append(std::string word) {}
};

