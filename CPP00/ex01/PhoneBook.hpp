/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:00:10 by gkoksal           #+#    #+#             */
/*   Updated: 2024/10/01 16:41:26 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cctype>
#include "Contacts.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void searchContacts(void);
		void addContact(void);

	private:
		std::string truncateString(const std::string& str);
		int			_contactCount;
		Contact		_contacts[8];
};

std::string toUpper(const std::string& str);

#endif
