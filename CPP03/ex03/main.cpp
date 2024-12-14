/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:57:29 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/04 09:57:30 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	// Create a DiamondTrap with a specific name
	DiamondTrap diamond("Shiny");
	// Test the whoAmI function to check name functionality
	std::cout << "\nTesting whoAmI function:" << std::endl;
	diamond.whoAmI();
	// Test attack function (inherited from ScavTrap)
	std::cout << "\nTesting attack functionality:" << std::endl;
	for (int i = 0; i < 5; i++)
		diamond.attack("target");
	// Test taking damage and repair functionality
	std::cout << "\nTesting takeDamage and beRepaired functionality:" << std::endl;
	diamond.takeDamage(30); // Take some damage
	diamond.beRepaired(20); // Repair some HP
	diamond.takeDamage(50); // Take more damage
	diamond.beRepaired(10); // Attempt to repair again
	// Take enough damage to reduce HP to zero
	std::cout << "\nTesting takeDamage to reduce HP to zero:" << std::endl;
	diamond.takeDamage(100);
	// Try to attack and repair when HP is zero
	std::cout << "\nAttempting to attack and repair when HP is zero:" << std::endl;
	diamond.attack("target");
	diamond.beRepaired(10);

	// Create a second DiamondTrap to test copy functionality
	std::cout << "\nTesting copy constructor and assignment operator:" << std::endl;
	DiamondTrap diamondCopy(diamond); // Copy constructor
	diamondCopy.whoAmI();			  // Check names in the copy

	DiamondTrap assignedDiamond("Temporary");
	assignedDiamond = diamond; // Assignment operator
	assignedDiamond.whoAmI();  // Check names in the assigned object

	return 0;
}
