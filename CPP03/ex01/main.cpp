/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:56:38 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/04 09:56:39 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ScavTrap scav("Scavvy");

	// Test attack function until energy is depleted
	std::cout << "Testing attack when alive and with energy:" << std::endl;
	for (int i = 0; i < 55; i++)
		scav.attack("target");
	// Attempt to attack with no energy left
	std::cout << "\nAttempting to attack with no energy left:" << std::endl;
	scav.attack("target");
	// Test takeDamage function
	std::cout << "\nTesting takeDamage:" << std::endl;
	scav.takeDamage(30);
	scav.takeDamage(40);
	scav.takeDamage(40); // This should reduce HP to zero and indicate "ScavTrap is dead!"
	// Attempt to take more damage when dead
	std::cout << "\nAttempting to take more damage when dead:" << std::endl;
	scav.takeDamage(10);
	// Test beRepaired function when dead
	std::cout << "\nTesting beRepaired when dead:" << std::endl;
	scav.beRepaired(20);
	// Create a new ScavTrap with full health and energy for repair test

	std::cout << "\nCreating a new ScavTrap for repair tests:" << std::endl;
	ScavTrap healthyScav("HealthyScavvy");
	std::cout << "\nTesting beRepaired when alive and with energy:" << std::endl;
	for (int i = 0; i < 5; i++)
		healthyScav.beRepaired(10);
	// Deplete energy and attempt repair with no energy left
	std::cout << "\nDepleting energy for repair test:" << std::endl;
	for (int i = 0; i < 50; i++)
		healthyScav.attack("dummy");
	std::cout << "\nAttempting to repair with no energy left:" << std::endl;
	healthyScav.beRepaired(5);
	// Test guardGate function
	std::cout << "\nTesting guardGate function:" << std::endl;
	healthyScav.guardGate();

	return 0;
}
