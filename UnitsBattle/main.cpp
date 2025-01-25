#include "Mage.h"
#include "Archer.h"
#include "Swordsman.h"
#include "Team.h"


bool Team::isFirst = true;

int main()
{
	Stick wand("stafff", 10, Common);
	Mage mage("warlock", 100, wand);
	std::cout << mage;

	Bow bow("Short bow", 10, Epic);
	Archer archer("Legalas", 50, bow);
	std::cout << archer;
	mage.Defense();
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

	Swordsman srordsman1("Jayeun1", 100, sword, 3);
	Swordsman srordsman2("Jayeun2", 100, sword, 3);
	Swordsman srordsman3("Jayeun2", 100, sword, 3);
	Archer archer1("Legalas1", 50, bow);
	Archer archer2("Legalas2", 50, bow);
	Archer archer3("Legalas3", 50, bow);



	Team team = { srordsman1, srordsman2, srordsman3 };
	Team team2 = { archer1, archer2, archer3 };

	team.Attack(team2);

}

