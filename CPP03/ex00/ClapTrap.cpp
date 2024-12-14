/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:56:21 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/04 09:56:22 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hp(10), _energy(10), _ap(0) {
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hp(10), _energy(10), _ap(0) {
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other):_hp(10), _energy(10), _ap(0) {
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other)
		_name = other._name;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_energy > 0 && _hp > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
		<< _ap << " points of damage !" << std::endl;
		_energy--;
	}
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " has no energy to attack !" << std::endl;
	else if (_hp < 0)
		std::cout << "ClapTrap " << _name << " has no hit points left to attack !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hp == 0) {
		std::cout << "ClapTrap " << _name << " is already dead !" << std::endl;
		return ;
	}
	if (amount < _hp) {
		_hp -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " amount of damage !" << std::endl;
	}
	else if (amount >= _hp ){
		std::cout << "ClapTrap " << _name << " takes " << amount << " amount of damage !" << std::endl;
		std::cout << "ClapTrap " << _name << " is dead !" <<  std::endl;
		_hp = 0;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy > 0 && _hp > 0) {
		std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " health points ! (HP:" << _hp << ")"<< std::endl;
		_energy--;
		_hp += amount;
	}
	else if (_energy == 0)
		std::cout << "ClapTrap " << _name << " has no energy to repair itself !" << std::endl;
	else if (_hp < 0)
		std::cout << "ClapTrap " << _name << " is already dead !" << std::endl;
}
