#include "Mage.h"
#include "Archer.h"
#include "Swordsman.h"
#include "Team.h"
#include "Battle.h"


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
	Mage Mage1("Warlock1", 50, wand);
	Mage Mage2("Warlock2", 50, wand);
	Mage Mage3("Warlock3", 50, wand);

	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

	Team team;
	team.Append(srordsman1);
	team.Append(srordsman2);
	team.Append(srordsman3);
	Team team2;
	team2.Append(archer1);
	team2.Append(archer2);
	team2.Append(archer3);
	Team team3;
	team3.Append(Mage1);
	team3.Append(Mage2);
	team3.Append(Mage3);
	team.Show();
	team2.Show();
	team3.Show();
	std::cout << team.getSize() << " " << team2.getSize() << std::endl;

	//Team team3 = {Mage1, Mage2, Mage3};

	/*team.Attack(team2);
	team2.Show();
	std::cout << team2.getSize() << std::endl;*/

	team.setName("Swordsmen");
	team2.setName("Archer");
	Battle battle;
	battle.Append(team);
	battle.Append(team2);
	battle.Start();

}

