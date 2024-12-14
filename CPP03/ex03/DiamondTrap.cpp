/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:57:19 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/04 09:57:20 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called." << std::endl;
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_ap = FragTrap::_ap;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	std::cout << "DiamondTrap constructor called." << std::endl;
	_name = name;
	_hp = FragTrap::_hp;
	_energy = ScavTrap::_energy;
	_ap = FragTrap::_ap;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	*this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hp = other._hp;
		_energy = other._energy;
		_ap = other._ap;
		ClapTrap::_name = _name + "_clap_name";
	}
	std::cout << "DiamondTrap copy assignment operator called for " << other._name << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called." << std::endl;
}

void DiamondTrap::attack(std::string const& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
		std::cout << "My DiamondTrap name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
