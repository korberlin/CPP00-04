#include "Zombie.hpp"

int main(void) {
	randomChump("Hector");
	Zombie *sara = newZombie("Sara");
	sara->announce();
	delete sara;
	return (0);
}