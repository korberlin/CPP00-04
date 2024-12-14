/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:32:44 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/06 15:19:31 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat default constructor called." << std::endl;
	_brain = new Brain;
}

Cat::Cat(const Cat& other): Animal(other) {
	*this = other;
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->_brain;
		if (other._brain)
			this->_brain = new Brain(*other._brain);
		else
			this->_brain = NULL;
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor called." << std::endl;
	delete _brain;
}

void Cat::makeSound(void) const {
	std::cout << "Cat goes meow!" << std::endl;
}

Brain* Cat::getBrain(void) const {
	return _brain;
}
