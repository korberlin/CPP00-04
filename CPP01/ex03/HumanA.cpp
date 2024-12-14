#include "HumanA.hpp"


HumanA::HumanA(const std::string& name, Weapon &weapon): _weapon(weapon), _name(name) {

}

void HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA() {

} 
