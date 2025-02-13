#include "Game.h"
#include "ConsoleGameView.h"
#include <Windows.h>

int main()
{

	srand(time(0));


	/*WordsManager wmanager;
	for (auto word : wmanager.GetWords())
	{
		std::cout << word << std::endl;
	}*/


	//std::vector<std::string> words;
	//std::string name("words.txt");
	//std::fstream stream(name, std::ios::in);
	//if (stream.is_open())
	//{
	//	std::string word;
	//	while (stream.good())
	//	{
	//		stream >> word;
	//		words.emplace_back(word);
	//	}
	//}
	//Cryptographer crypt;
	////std::vector<std::string> vec(crypt.Encrypt(words));
	////for (std::string word : vec)
	////{
	////	std::cout << word << std::endl;
	////}

	//std::vector<std::string> vec2(crypt.ReEncrypt());
	//for (std::string word : vec2)
	//{
	//	std::cout << word << std::endl;
	//}


	Game game(std::make_shared<WordsManager>(), std::make_unique<ConsoleGameView>());
	game.Start();


	return 0;
}