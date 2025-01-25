#pragma once
#include "Unit.h"


class Archer : public Unit
{
protected:
	unsigned int arrows = 10;
public:
	Archer(const char* name, int hitpoints, Bow& bow);
	Archer(std::string name);
	int Attack(Unit& other);
};

