#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;
	public:
		void setWeapon(Weapon& weapon);
		void attack(void);
		HumanB(const std::string& name);
		~HumanB(void);
};