#include "Zombie.hpp"

Zombie::Zombie(void) {

}

Zombie::~Zombie(void) {
	std::cout << this->name << " has been destroyed." << std::endl;
}

void Zombie::setZombieName(std::string& name) {
	this->name = name;
}

void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}