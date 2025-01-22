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
	size_t _speed;
	std::string _name;
	bool isAlive = true;
	bool isInDefense = false;
public:
	Unit(const char* name, int hitpoints);
	Unit(const char* name, int hitpoints, Weapon& weapon);
	/*Unit(std::string name);*/
	void GetHit(int damage);
	int Attack(Unit& other);
	bool Defense();
	friend std::ostream& operator<<(std::ostream& os, const Unit& self)
	{
		os << "Name - " << self._name << ". Hitpoints - " << self._hitpoints << ". Weapon: " << *(self._weapon);
		os << std::endl;
		return os;
		
	};

};

