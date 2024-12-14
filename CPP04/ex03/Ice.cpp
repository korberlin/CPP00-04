/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:46:27 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/06 11:40:47 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {

}

Ice::Ice(const Ice &other): AMateria(other) {

}

Ice& Ice::operator=(const Ice &other) {
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {

}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
