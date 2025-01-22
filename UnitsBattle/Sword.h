#pragma once
#include "Weapon.h"
class Sword : public Weapon
{
public:
	Sword(const char* name, int damage, Grade grade);
	int getDamage();
};

