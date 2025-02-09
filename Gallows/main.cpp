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

	Game game(std::make_shared<WordsManager>(), std::make_unique<ConsoleGameView>());
	game.Start();

	return 0;
}