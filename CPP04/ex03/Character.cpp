/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:53:30 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/06 15:19:31 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string &name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_amateria[i] = NULL;
}

Character::Character(const Character &other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		if (other._amateria[i])
			_amateria[i] = other._amateria[i]->clone();
		else
			_amateria[i] = NULL;
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_amateria[i])
				delete _amateria[i];
			if (other._amateria[i])
				_amateria[i] = other._amateria[i]->clone();
			else
				_amateria[i] = NULL;
		}
		_name = other._name;
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		if (_amateria[i])
			delete _amateria[i];
}

const std::string &Character::getName() const {
	return _name;
}

void Character::equip(AMateria *m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_amateria[i]) {
			_amateria[i] = m;
			return;
		}
	}
	std::cout << "Character " << _name << "'s inventory is already full" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4) {
		if (_amateria[idx]) {
			std::cout << "Character " << _name << " has unequipped the " << _amateria[idx]->getType() << std::endl;
			_amateria[idx] = NULL;
		}
		else
			std::cout << "There is nothing to unequip in that inventory slot." << std::endl;
	}
	else
		std::cout << "Index is out of inventory boundaries." << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4) {
		if (_amateria[idx])
			_amateria[idx]->use(target);
		else
			std::cout << "Character has no materia in that slot." << std::endl;
	}
	else
		std::cout << "Index is out of inventory boundaries." << std::endl;
}
