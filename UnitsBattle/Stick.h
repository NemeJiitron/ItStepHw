#pragma once
#include "Weapon.h"


class Stick : public Weapon
{
protected:
	int charges;	
public:
	int getDamage();
};

