/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:57:07 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/04 09:57:08 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	_hp = 100;
	_energy = 50;
	_ap = 20;
	std::cout << "ScavTrap's default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) {
	_hp = 100;
	_energy = 50;
	_ap = 20;
	std::cout << "ScavTrap's constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
	_name = other._name;
	_hp = other._hp;
	_energy = other._energy;
	_ap = other._ap;
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		std::cout << "ScavTrap assignment operator called for " << _name << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_hp == 0)
		std::cout << "ScavTrap " << _name << " has no HP left to attack !!" << std::endl;
	else if (_energy == 0)
		std::cout << "ScavTrap " << _name << " has no energy to attack !" << std::endl;
	else {
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
	<< _ap << " points of damage !" << std::endl;
	_energy--;
	}
}

void ScavTrap::guardGate(void) {
	if (_hp == 0)
		std::cout << "ScavTrap " << _name << " has no HP left to make a move !!" << std::endl;
	else if (_energy == 0)
		std::cout << "ScavTrap " << _name << " has no energy to make a move !" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is in the guard mode !" << std::endl;
}
