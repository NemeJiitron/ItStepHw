#include "Weapon.h"

namespace Weapons
{

	Weapon::Weapon(const char* name, int damage, Grade grade)
		: _name(name), _grade(grade), _damage(damage)
	{
	}

	int Weapon::getDamage()
	{
		return _damage * (_grade + 1);
	}

	void Weapon::Upgrade()
	{
		switch (_grade)
		{
		case Common:
			_grade = Uncommon;
			break;
		case Uncommon:
			_grade = Epic;
			break;
		case Epic:
			_grade = Mythical;
			break;
		case Mythical:
			_grade = Legendary;
			break;
		case Legendary:
			std::cout << "Is already Legendary" << std::endl;
			break;
		default:
			break;
		}
	}

	void Weapon::Show()
	{
		std::cout << "Weapon name - " << _name << "\nWeapon damage - " << _damage << "\nGrade - " << _grade << std::endl;
	}

}