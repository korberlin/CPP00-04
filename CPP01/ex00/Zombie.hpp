#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setZombieName(std::string& name);
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif