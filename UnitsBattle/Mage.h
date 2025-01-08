#pragma once
#include "Unit.h"

class Mage : public Unit
{
protected:
	unsigned int mana;
public:
	Mage(std::string name, int hitpoints, unsigned int mana);
	Mage(std::string name);
	void Defense();
	void Attack(Unit other); 
};

