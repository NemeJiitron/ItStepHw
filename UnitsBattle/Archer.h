#pragma once
#include "Unit.h"
#include "Bow.h"

namespace Units {

	class Archer : virtual public Unit
	{
	protected:
		unsigned int arrows = 10;
	public:
		Archer(const char* name, int hitpoints, Weapons::Bow& bow);
		Archer(std::string name);
		int Attack(Unit& other);
	};

}