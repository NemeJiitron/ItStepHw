#pragma once
#include "Weapon.cpp"
#include <iostream>

class Unit
{
protected:
	int HitPoints;
	Weapon weapon;
	size_t speed;
	std::string name;
public:
	Unit(std::string name, int hitpoints);
	Unit(int hitpoints);
	Unit(std::string name);
	void Attack(Unit other);
	void Defense();
	std::ostream Print();

};

