#pragma once
#include "Unit.h"
class Swordsman : public Unit
{
protected:
	unsigned int power;
public:
	Swordsman(std::string name, int hitpoints, unsigned int power);
	Swordsman(std::string name);
	void Attack(Unit other);
	void Defense();
};

