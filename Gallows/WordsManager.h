#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class WordsManager
{
private:
	std::vector<std::string> words;
public:
	WordsManager()
	{
		Load();
	}
	const std::vector<std::string>& GetWords() const
	{	
		return words;
	}
	void Save() {}
	void Load()
	{
		std::string name("words.txt");
		std::fstream stream(name, std::ios::in);
		if (stream.is_open())
		{
			std::string word;
			while (stream.good())
			{
				stream >> word;
				words.emplace_back(word);
			}

			/*int i = 0;
			while (true)
			{
				std::string word;
				char ch = stream.get();
				while (ch != '\n' && !stream.eof())
				{
					word += ch;
				}
				if (stream.eof())
				{
					word += ch;
					words[i] = word;
					i++;
					break;
				}
				word.shrink_to_fit();
				words[i] = word;
				i++;
				word.clear();
			}*/
		}
	
		words.shrink_to_fit();
	}
	void Append(std::string word) {}
};

