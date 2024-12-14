/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <	gkoksal@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:04:00 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/05 10:52:38 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Animal Class

Animal::Animal() {
	std::cout << "Animal default constructor called." << std::endl;
	_type = "Animal";
}

Animal::Animal(const std::string& type): _type(type) {
	std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor called." << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called." << std::endl;
}

const std::string& Animal::getType(void) const {
	return _type;
}

void Animal::makeSound(void) const {
	std::cout << "I am just a regular animal and I don't have specific sound..." << std::endl;
}
