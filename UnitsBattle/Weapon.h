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
	Grade _grade;
	std::string _name;
	int _damage;
public:
	Weapon(const char* _name, int damage, Grade _grade);
	Weapon(std::string _name);
	int getDamage();
	void Upgrade();
	void Show();
	friend std::ostream& operator<<(std::ostream& os, const Weapon& self)
	{
		os << "Weapon name - " << self._name << ". Weapon damage - " << self._damage << ". Grade - " << self._grade;
		os << std::endl;
		return os;
	};
};

