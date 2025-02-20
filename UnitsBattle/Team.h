#pragma once
#include <iostream>
#include "Mage.h"
#include "Archer.h"
#include "Swordsman.h"
#include <vector>



class Team
{
protected:
	static bool isFirst;
	std::vector<Units::Unit*> units;
	std::string name;
	Units::Unit& GetRandomTarget(Team& targets);
	void anyDead();
public:
	Team();
	//Team(std::initializer_list<Unit*> list);
	void setName(const char* name);
	std::string getName();
	size_t getSize();
	bool isEmpty();
	void Append(const Units::Unit& unit);
	void Attack(Team& enemies);
	void Show();
	void Defense();
};
