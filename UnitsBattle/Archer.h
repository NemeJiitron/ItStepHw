#pragma once
#include "Unit.h"
class Archer : public Unit
{
protected:
	unsigned int arrows;
public:
	Archer(std::string name, int hitpoints, unsigned int arrows);
	Archer(std::string name);
	void Attack(Unit other);
	void Defense();
};

