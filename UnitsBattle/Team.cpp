#include "Team.h"

Units::Unit& Team::GetRandomTarget(Team& targets)
{
	int rand_index = rand() % targets.units.size();
	return *(targets.units[rand_index]);
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

//Team::Team(const std::initializer_list<Unit*> list)
//	: Team()
//{
//	Unit* const *begin = list.begin();																
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

bool Team::isEmpty()
{
	if (units.size() == 0)
	{
		return true;
	}
	return false;
}

void Team::Append(const Units::Unit& unit)
{
	units.push_back(const_cast<Units::Unit*>(&unit));
}

void Team::Attack(Team& enemies)
{
	for (size_t i = 0; i < units.size(); i++){
		Units::Unit& target = GetRandomTarget(enemies);
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

void Team::Defense()
{
	for (size_t i = 0; i < units.size(); i++)
	{
		units[i]->Defense();
	}
}
