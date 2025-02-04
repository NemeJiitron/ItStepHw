#pragma once
#include "Unit.h"
#include "Sword.h"


namespace Units {


	class Swordsman : virtual public Unit
	{
	protected:
		unsigned int power;
	public:
		Swordsman(const char* name, int hitpoints, Weapons::Sword& sword, unsigned int pwr);
		Swordsman(std::string name);
		int Attack(Unit& other);
	};

}