#pragma once
#include "Bow.h"
#include "Stick.h"
#include "Sword.h"
#include <iostream>

namespace Units {


class Unit
{

protected:
	int _hitpoints;
	Weapons::Weapon* _weapon;
	size_t armor;
	std::string _name;
	bool InDefense = false;
	void DamageMessage(int damage);
public:
	Unit(const char* name, int hitpoints);
	Unit(const char* name, int hitpoints, size_t armor, Weapons::Weapon& weapon);
	/*Unit(std::string name);*/
	virtual int GetHit(int damage);
	virtual int Attack(Unit& other) = 0;
	bool isAlive();
	bool isInDefense();
	int getArmor();
	virtual bool Defense();
	friend std::ostream& operator<<(std::ostream& os, const Unit& self)
	{
		os << "Name - " << self._name << ". Hitpoints - " << self._hitpoints << ". Weapon: " << *(self._weapon);
		os << std::endl;
		return os;
		
	};

};

}
