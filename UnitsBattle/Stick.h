#pragma once
#include "Weapon.h"

namespace Weapons
{
	class Stick : public Weapon
	{
	protected:
		int charges = 10;	
	public:
		Stick(const char* name, int damage, Grade grade);
		int getDamage();
	};
}

