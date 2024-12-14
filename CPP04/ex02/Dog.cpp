/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:32:47 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/06 15:19:31 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog default constructor called." << std::endl;
	_brain = new Brain;
}

Dog::Dog(const Dog& other): Animal(other) {
	std::cout << "Dog copy constructor called." << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		delete this->_brain;
		Animal::operator=(other);
		if (other._brain)
			this->_brain = new Brain(*other._brain);
		else
			this->_brain = NULL;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
	delete _brain;
}

void Dog::makeSound(void) const {
	std::cout << "Dog goes woof!" << std::endl;
}

Brain* Dog::getBrain(void) const {
	return _brain;
}
