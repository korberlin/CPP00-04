#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
	private:
		Weapon& _weapon;
		std::string _name;
	public:
		void attack(void);
		HumanA(const std::string& name, Weapon &weapon);
		~HumanA(void);
};
