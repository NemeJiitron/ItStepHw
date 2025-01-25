#pragma once
#include <iostream>
#include "Unit.h"
#include <vector>



class Team
{
	struct target
	{
		Unit& unit;
		int index;
	};
protected:
	static bool isFirst;
	std::vector<target> targets;
	std::vector<Unit> units;
	std::string name;
	Unit& GetRandomTarget(Team& tergets);
	void anyDead();
public:
	Team();
	Team(const std::initializer_list<Unit>& list);
	void setName(const char* name);
	std::string getName();
	void Append(Unit& unit);
	void Attack(Team& enemies);
};
