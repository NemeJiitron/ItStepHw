#pragma once
#include<vector>
#include"Team.h"


class Battle
{
	struct BattleTeam {
		Team* team;
		int team_id;
		bool have_attack = true;
		int turns_count;
		BattleTeam(Team* team, int team_id, int turns_count);
		void Turn();
		int canTurn();
	};
private:
	std::vector<BattleTeam> teams;
	int max_teams;
	int max_turns_count;
	void Stop();
	BattleTeam& getRandomTeam();
	bool someoneHasAttack();
public:
	Battle();
	Battle(std::initializer_list<Team> list);
	void Append(const Team& unit);
	void Start();

};

