/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:32:40 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/06 10:32:41 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called." << std::endl;
	for (int i = 0; i < 100; i++) {
		std::stringstream ss;
		ss << "Idea number: " << i;
		this->_ideas[i] = ss.str();
	}
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called." << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called." << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called." << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return _ideas[index];
	}
	else {
		return "";
	}
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}
