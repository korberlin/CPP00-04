/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:56:59 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/04 09:57:00 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap's default constructor called" << std::endl;
	_hp = 100;
	_energy = 100;
	_ap = 30;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
	std::cout << "FragTrap's constructor called" << std::endl;
	_hp = 100;
	_energy = 100;
	_ap = 30;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
	_name = other._name;
	_hp = other._hp;
	_energy = other._energy;
	_ap = other._ap;
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other){
		ClapTrap::operator=(other);
		std::cout << "FragTrap assignment operator called for " << _name << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap's destructor called" << std::endl;
}

void FragTrap::highFiveGuys(void) {
		if (_hp == 0)
		std::cout << "FragTrap " << _name << " has no HP left to make a move !!" << std::endl;
	else if (_energy == 0)
		std::cout << "FragTrap " << _name << " has no energy to make a move !" << std::endl;
	else
		std::cout << "FragTrap " << _name << " asks for high five !" << std::endl;
}
