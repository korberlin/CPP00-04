/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:57:05 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/04 09:57:06 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
	FragTrap frag("Fraggy");
	// Test attack function until energy is depleted
	std::cout << "Testing attack when alive and with energy:" << std::endl;
	 // Loop to fully deplete energy
	for (int i = 0; i < 105; i++)
		frag.attack("target");
	// Attempt to attack with no energy left
	std::cout << "\nAttempting to attack with no energy left:" << std::endl;
	frag.attack("target");
	// Test takeDamage function
	std::cout << "\nTesting takeDamage:" << std::endl;
	frag.takeDamage(30);
	frag.takeDamage(40);
	frag.takeDamage(40); // This should reduce HP to zero and indicate "FragTrap is dead!"
	// Attempt to take more damage when dead
	std::cout << "\nAttempting to take more damage when dead:" << std::endl;
	frag.takeDamage(10);
	// Test beRepaired function when dead
	std::cout << "\nTesting beRepaired when dead:" << std::endl;
	frag.beRepaired(20);
	// Test highFiveGuys when dead
	std::cout << "\nTesting highFiveGuys when dead:" << std::endl;
	frag.highFiveGuys();

	// Create a new FragTrap with full health and energy for repair and high five tests
	std::cout << "\nCreating a new FragTrap for repair and high five tests:" << std::endl;
	FragTrap healthyFrag("HealthyFraggy");
	// Testing beRepaired when alive and with energy
	std::cout << "\nTesting beRepaired when alive and with energy:" << std::endl;
	for (int i = 0; i < 5; i++)
		healthyFrag.beRepaired(10);
	// Testing highFiveGuys when alive and with energy
	std::cout << "\nTesting highFiveGuys when alive and with energy:" << std::endl;
	healthyFrag.highFiveGuys();
	// Deplete energy and attempt high five with no energy left
	std::cout << "\nDepleting energy for high five test:" << std::endl;
	for (int i = 0; i < 100; i++)
		healthyFrag.attack("dummy");
	std::cout << "\nAttempting to high five with no energy left:" << std::endl;
	healthyFrag.highFiveGuys();

	return 0;
}
