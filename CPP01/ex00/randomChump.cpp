#include "Zombie.hpp"

void randomChump(std:: string name) {
	Zombie newZombie;
	newZombie.setZombieName(name);
	newZombie.announce();
}