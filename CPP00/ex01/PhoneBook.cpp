/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:59:50 by gkoksal           #+#    #+#             */
/*   Updated: 2024/10/01 14:00:48 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	_contactCount = 0;
	return ;
}

PhoneBook:: ~PhoneBook(void) {
	return ;
}

std::string toUpper(const std::string& str)
{
	std::string upperStr;
	for (size_t i = 0; i < str.length(); i++) {
		upperStr += std::toupper(str[i]);
	}
	return upperStr;
}

std::string PhoneBook::truncateString(const std::string& str) {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}

void PhoneBook::addContact(void) {
	Contact newContact;
	std::string temp;
	int index = _contactCount % 8;

	do {
		std::cout << "Please provide the contact's first name: ";
		std::getline(std::cin, temp);
		newContact.setFirstName(temp);
	} while (newContact.getFirstName().empty());

	do {
		std::cout << "Please provide the contact's last name: ";
		std::getline(std::cin, temp);
		newContact.setLastName(temp);
	} while (newContact.getLastName().empty());

	do {
		std::cout << "Please provide the contact's nickname: ";
		std::getline(std::cin, temp);
		newContact.setNickName(temp);
	} while (newContact.getNickName().empty());

	do {
		std::cout << "Please provide the contact's phone number: ";
		std::getline(std::cin, temp);
		newContact.setPhoneNumber(temp);
	} while (newContact.getPhoneNumber().empty());

	do {
		std::cout << "Please provide the contact's darkest secret: ";
		std::getline(std::cin, temp);
		newContact.setDarkestSecret(temp);
	} while (newContact.getDarkestSecret().empty());

	_contacts[index] = newContact;
	_contactCount++;
	std::cout << "Contact has been added to the phonebook!" << std::endl;
}

void PhoneBook::searchContacts(void) {
	int	maxIndex;
	int index;
	std::string input;

	if (_contactCount < 8)
		maxIndex = _contactCount;
	else
		maxIndex = 8;
	if (_contactCount == 0) {
		std::cout << "PhoneBook is empty. Please provide some contacts first." << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < maxIndex; i++) {
		std::cout << std::right << std::setw(10) << i << "|"
				  << std::setw(10) << truncateString(_contacts[i].getFirstName()) << "|"
				  << std::setw(10) << truncateString(_contacts[i].getLastName()) << "|"
				  << std::setw(10) << truncateString(_contacts[i].getNickName()) << "|" << std::endl;
	}
	std::cout << "Please provide the index of the contact to display or enter `BACK` to return to main menu" << std::endl;
	std::getline(std::cin, input);
	if (toUpper(input) == "BACK")
		return ;
	std::stringstream ss(input);
	if (!(ss >> index) || index < 0 || index >= maxIndex) {
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickName() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
 
}
