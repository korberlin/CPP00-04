/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:31:31 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/06 10:31:32 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Dog goes woof!" << std::endl;
}

