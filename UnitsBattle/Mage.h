#pragma once
#include "Unit.h"
#include "Stick.h"

class Mage : public Unit
{
protected:
	unsigned int mana;
public:
	Mage(const char* name, int hitpoints, Stick& stick);
	Mage(std::string name);
	void Defense();
	int Attack(Unit& other);
};

