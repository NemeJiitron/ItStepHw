#include "Mage.h"
#include "Archer.h"
#include "Swordsman.h"
#include "Team.h"


bool Team::isFirst = true;

int main()
{
	Stick wand("stafff", 10, Common);
	Bow bow("Short bow", 10, Epic);
	Sword sword("Spatha", 10, Epic);

	//Mage mage("warlock", 100, wand);
	//std::cout << mage;
	//Archer archer("Legalas", 50, bow);
	//std::cout << archer;
	//mage.Defense();
	//mage.Attack(archer);
	//std::cout << archer;
	//archer.Attack(mage);
	//std::cout << mage;

	//Swordsman srordsman("Jayeun", 100, sword, 3);
	//std::cout << srordsman;
	//srordsman.Attack(archer);
	//std::cout << archer;

	Swordsman srordsman1("Jayeun1", 100, sword, 3);
	Swordsman srordsman2("Jayeun2", 100, sword, 3);
	Swordsman srordsman3("Jayeun3", 100, sword, 3);
	Archer archer1("Legalas1", 50, bow);
	Archer archer2("Legalas2", 50, bow);
	Archer archer3("Legalas3", 50, bow);

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

	Team team;
	team.Append(srordsman1);
	team.Append(srordsman2);
	team.Append(srordsman3);
	Team team2;
	team2.Append(archer1);
	team2.Append(archer2);
	team2.Append(archer3);
	team.Show();
	team2.Show();
	std::cout << team.getSize() << " " << team2.getSize() << std::endl;

	//Team team = { srordsman1, srordsman2, srordsman3 };
	//Team team2 = { archer1, archer2, archer3 };

	team.Attack(team2);
	team2.Show();
	std::cout << team2.getSize();
}

