#pragma once
#include "Unit.h"
#include "Sword.h"
class Swordsman : public Unit
{
protected:
	unsigned int power;
public:
	Swordsman(const char* name, int hitpoints, Sword& sword, unsigned int pwr);
	Swordsman(std::string name);
	int Attack(Unit& other);
};

