/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:32:12 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/06 10:32:13 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "================= Animal Collection Test =================\n";
	const int animalCount = 10;
	Animal *animalShelter[animalCount];

	// Populate the array with alternating Dogs and Cats
	for (int i = 0; i < animalCount; i++)
	{
		if (i % 2 == 0)
			animalShelter[i] = new Dog();
		else
			animalShelter[i] = new Cat();
	}
	// Display types and make sounds
	for (int i = 0; i < animalCount; i++)
	{
		std::cout << "Animal at index " << i << " is a " << animalShelter[i]->getType() << "\n";
		animalShelter[i]->makeSound();
	}
	// Clean up: delete the animals
	for (int i = 0; i < animalCount; i++)
		delete animalShelter[i];

	std::cout << "================= Deep Copy Verification =================\n";
	// Dog deep copy test
	std::cout << "\n--- Dog Deep Copy Test ---\n";
	Dog firstDog;
	firstDog.getBrain()->setIdea(0, "Guard the house");
	Dog secondDog(firstDog); // Copy constructor
	secondDog.getBrain()->setIdea(0, "Play with the ball");
	std::cout << "First dog's idea[0]: " << firstDog.getBrain()->getIdea(0) << "\n";
	std::cout << "Second dog's idea[0]: " << secondDog.getBrain()->getIdea(0) << "\n";
	// Cat deep copy test
	std::cout << "\n--- Cat Deep Copy Test ---\n";
	Cat firstCat;
	firstCat.getBrain()->setIdea(0, "Nap in the sun");
	Cat secondCat;
	secondCat = firstCat; // Assignment operator
	secondCat.getBrain()->setIdea(0, "Explore the garden");
	std::cout << "First cat's idea[0]: " << firstCat.getBrain()->getIdea(0) << "\n";
	std::cout << "Second cat's idea[0]: " << secondCat.getBrain()->getIdea(0) << "\n";

	return 0;
}
