/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:31:35 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/06 11:42:27 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {

}

Cure::Cure(const Cure& other): AMateria(other) {

}

Cure& Cure::operator=(const Cure &other) {
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {

}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
