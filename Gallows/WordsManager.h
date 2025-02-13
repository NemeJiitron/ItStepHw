#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Cryptographer.h"

class WordsManager
{
private:
	std::vector<std::string> words;
	Cryptographer crypt;
public:
	WordsManager()
	{
		Load();
	}
	const std::vector<std::string>& GetWords() const
	{	
		return words;
	}
	void Save(std::vector<std::string> out_words)
	{
		crypt.Encrypt(out_words);
	}
	void Save()
	{
		crypt.Encrypt(words);
	}
	void Load()
	{
		words = crypt.ReEncrypt();
	}
	void Append(std::string word) 
	{
		words.push_back(word);
	}
};

