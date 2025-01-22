#include "Mage.h"
#include "Archer.h"
#include "Swordsman.h"



int main()
{
	Stick wand("stafff", 10, Common);
	Mage mage("warlock", 100, wand);
	std::cout << mage;

	Bow bow("Short bow", 10, Epic, 30);
	Archer archer("Legalas", 50, bow);
	std::cout << archer;

	mage.Attack(archer);
	std::cout << archer;
	archer.Attack(mage);
	archer.Attack(mage);
	archer.Attack(mage);
	archer.Attack(mage);
	archer.Attack(mage);
	archer.Attack(mage);
	std::cout << mage;

	Sword sword("Spatha", 10, Epic);
	Swordsman srordsman("Jayeun", 100, sword, 3);
	std::cout << srordsman;
	srordsman.Attack(archer);
	std::cout << archer;


}

