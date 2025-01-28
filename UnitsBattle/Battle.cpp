#include "Battle.h"

Battle::BattleTeam& Battle::getRandomTeam()
{
	int rand_index;
	rand_index = rand() % teams.size();
	do {
		int rand_index = rand() % teams.size();
	} while (teams[rand_index].team->isEmpty() && teams[rand_index].have_attack == false);
	return teams[rand_index];
}

bool Battle::someoneHasAttack()
{
	for (size_t i = 0; i < teams.size(); i++)
	{
		if (!teams[i].canTurn())
		{
			return false;
		}
	}
	return true;
}

Battle::Battle()
	: max_teams(2), max_turns_count(20)
{
}

Battle::Battle(std::initializer_list<Team> list)
{
	const Team* begin = list.begin();
	max_turns_count = 20;
	max_teams = list.size();
	for (size_t i = 0; i < list.size(); i++)
	{
		teams.push_back(BattleTeam(const_cast<Team*>(begin), i, max_turns_count));
	}
}

void Battle::Append(const Team& unit)
{
	if (teams.size() == max_teams)
		throw std::exception("Max teams");
	if (teams.size() == 0)
	{
		teams.push_back(BattleTeam(const_cast<Team*>(&unit), 0, max_turns_count));
		return;
	}
	teams.push_back(BattleTeam(const_cast<Team*>(&unit), teams.back().team_id + 1, max_turns_count));
}

void Battle::Start()
{
	BattleTeam& currenteam = getRandomTeam();
	Team* target;
	while (someoneHasAttack())
	{
		
		for (size_t i = 0; i < teams.size(); i++)
		{
			if (currenteam.team_id != teams[i].team_id) 
			{
				target = teams[i].team;
				if (currenteam.canTurn())
				{
					currenteam.team->Attack(*target);
					currenteam.Turn();	
					if (target->isEmpty())
					{
						std::cout << "Team: " << currenteam.team->getName() << " killed " << target->getName() << std::endl;
						teams.erase(teams.cbegin() + i);
					}
				}
				else
				{
					std::cout << "Team: " << currenteam.team->getName() << " run out of turns\n";
				}


			}
		}
		if (teams.size() == 1)
		{
			std::cout << "Team: " << currenteam.team->getName() << " won!\n";
			break;
		}

		currenteam.have_attack = false;
		currenteam = getRandomTeam();

	}
}

Battle::BattleTeam::BattleTeam(Team* team, int team_id, int turns_count)
	:team(team), team_id(team_id), turns_count(turns_count)
{
}

void Battle::BattleTeam::Turn()
{
	turns_count -= team->getSize();
	std::cout << "Team: " << team->getName() << " turn\n";
}

int Battle::BattleTeam::canTurn()
{
	return turns_count > 0;
}
