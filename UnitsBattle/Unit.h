#pragma once
#include "Bow.h"
#include "Stick.h"
#include "Sword.h"
#include <iostream>

class Unit
{
protected:
	int _hitpoints;
	Weapon* _weapon;
	size_t armor;
	std::string _name;
	bool InDefense = false;
	void DamageMessage(Unit& other, int damage);
public:
	Unit(const char* name, int hitpoints);
	Unit(const char* name, int hitpoints, size_t armor, Weapon& weapon);
	/*Unit(std::string name);*/
	virtual int GetHit(int damage);
	virtual int Attack(Unit& other);
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

