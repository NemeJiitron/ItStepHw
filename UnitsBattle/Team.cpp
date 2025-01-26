#include "Team.h"

Unit& Team::GetRandomTarget(Team& targets)
{
	int rand_index = rand() % targets.units.size() + 1;
	return *(targets.units[rand_index - 1]);
}

void Team::anyDead()
{
	for (size_t i = 0; i < units.size(); i++)
	{
		if(!units[i]->isAlive())
		{
			units.erase(units.begin() + i);
		}
	}
}

Team::Team()
{
	if (isFirst)
	{
		isFirst = false;
		srand(time(0));
	}
}

//Team::Team(const std::initializer_list<Unit>& list)
//	: Team()
//{
//	const Unit* begin = list.begin();
//	for (size_t i = 0; i < list.size(); i++)
//	{
//		units.push_back(*begin);
//	}
//}

void Team::setName(const char* name)
{
	this->name = name;
}

std::string Team::getName()
{
	return name;
}

size_t Team::getSize()
{
	return units.size();
}

void Team::Append(Unit& unit)
{
	units.push_back(&unit);
}

void Team::Attack(Team& enemies)
{
	for (size_t i = 0; i < units.size(); i++){
		Unit& target = GetRandomTarget(enemies);
		units[i]->Attack(target);
		enemies.anyDead();
	}
}

void Team::Show()
{
	for (size_t i = 0; i < units.size(); i++)
	{
		std::cout << *(units[i]);
	}
}
