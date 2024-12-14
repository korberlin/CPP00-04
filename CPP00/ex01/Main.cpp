/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:04:54 by gkoksal           #+#    #+#             */
/*   Updated: 2024/10/07 11:04:55 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phoneBook;
	std::string command;
	std::cout << "Welcome to my Phone Book application" << std::endl;

	while (true) {

		std::cout << " Please enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (toUpper(command) == "ADD")
			phoneBook.addContact();
		else if (toUpper(command) == "SEARCH")
			phoneBook.searchContacts();
		else if (toUpper(command) == "EXIT")
			return (0);
		else
			continue;
	}
}
