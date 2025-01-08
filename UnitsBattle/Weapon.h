#pragma once
#include <iostream>

enum Grade
{
	Common,
	Uncommon,
	Epic,
	Mythical,
	Legendary
};

class Weapon
{
protected:
	Grade grade;
	std::string name;
	int damage;
public:
	Weapon(std::string name, Grade grade);
	Weapon(std::string name);
	int getDamage();
	void Upgrade();
};

