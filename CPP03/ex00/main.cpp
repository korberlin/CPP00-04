/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:56:26 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/04 09:56:26 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap clap("Clappy");

	// Test attack function until energy is depleted
	std::cout << "Testing attack when alive and with energy:" << std::endl;
	for (int i = 0; i < 12; i++)
		clap.attack("target");
	// Attempt to attack with no energy left
	std::cout << "\nAttempting to attack with no energy left:" << std::endl;
	clap.attack("target");
	// Test takeDamage function
	std::cout << "\nTesting takeDamage:" << std::endl;
	clap.takeDamage(3);
	clap.takeDamage(4);
	clap.takeDamage(10); // This should reduce HP to zero and indicate "ClapTrap is dead!"
	// Attempt to take more damage when dead
	std::cout << "\nAttempting to take more damage when dead:" << std::endl;
	clap.takeDamage(5);
	// Test beRepaired function when dead
	std::cout << "\nTesting beRepaired when dead:" << std::endl;
	clap.beRepaired(5);

	// Create a new ClapTrap with full health and energy for repair test
	std::cout << "\nCreating a new ClapTrap for repair tests:" << std::endl;
	ClapTrap healthyClap("HealthyClappy");
	std::cout << "\nTesting beRepaired when alive and with energy:" << std::endl;
	for (int i = 0; i < 5; i++)
		healthyClap.beRepaired(2);
	// Deplete energy and attempt repair with no energy left
	std::cout << "\nDepleting energy for repair test:" << std::endl;
	for (int i = 0; i < 10; i++)
		healthyClap.attack("dummy");
	std::cout << "\nAttempting to repair with no energy left:" << std::endl;
	healthyClap.beRepaired(5);

	return 0;
}
