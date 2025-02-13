#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Cryptographer
{
private:
	const static int key = 5;
	std::string encrypt_word(std::string& word)
	{
		std::string newWord;
		for (char ch : word)
		{
			newWord += ch + key;
		}
		newWord.shrink_to_fit();
		return newWord;
	};

	std::string re_encrypt_word(std::string& word)
	{
		std::string newWord;
		for (char ch : word)
		{
			newWord += ch - key;
		}
		newWord.shrink_to_fit();
		return newWord;
	};
public:
	const int getKey() const { return key; }
	std::string Encrypt(std::string word)
	{
		std::string name = "encrypted_words.txt";
		std::fstream stream(name, std::ios::app);
		std::string newWord = encrypt_word(word);
		stream << newWord;
		stream.put('\n');
		return newWord;
	};
	std::vector<std::string> Encrypt(std::vector<std::string>& words)
	{
		std::vector<std::string> newWords;
		for (std::string word : words)
		{
			newWords.push_back(Encrypt(word));
		}
		return newWords;
	};
	std::vector<std::string> ReEncrypt()
	{
		std::vector<std::string> words;
		std::string name = "encrypted_words.txt";
		std::fstream stream(name, std::ios::in);
		if (stream.is_open())
		{
			std::string word;
			while (stream.good())
			{
				stream >> word;
				words.emplace_back(re_encrypt_word(word));
			}
		}
		return words;
	};
};
