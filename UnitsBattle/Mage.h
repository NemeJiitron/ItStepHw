#pragma once
#include "Unit.h"
#include "Stick.h"

namespace Units {

	class Mage : virtual public Unit
	{
	protected:
		unsigned int mana;
	public:
		Mage(const char* name, int hitpoints, Weapons::Stick& stick);
		Mage(std::string name);
		int Attack(Unit& other);
	};

}