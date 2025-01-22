#include "Mage.h"

Mage::Mage(const char* name, int hitpoints, Stick& stick)
	: Unit::Unit(name, hitpoints, stick), mana(100)
{
}

int Mage::Attack(Unit& other)
{
	int damage = Unit::Attack(other);
	other.GetHit(damage);
	return damage;
}
