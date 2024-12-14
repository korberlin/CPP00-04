/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <	gkoksal@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:16:50 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/05 10:53:41 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Testing Animal hierarchy
	std::cout << "=== Animal Hierarchy Tests ===" << std::endl;
	const Animal *genericAnimal = new Animal();
	const Animal *rover = new Dog();
	const Animal *whiskers = new Cat();

	std::cout << std::endl;
	std::cout << "Type of genericAnimal: " << genericAnimal->getType() << std::endl;
	std::cout << "Type of rover: " << rover->getType() << std::endl;
	std::cout << "Type of whiskers: " << whiskers->getType() << std::endl;
	std::cout << std::endl;

	genericAnimal->makeSound(); // Should output the animal sound
	rover->makeSound();			// Should output the dog sound
	whiskers->makeSound();		// Should output the cat sound
	std::cout << std::endl;

	delete genericAnimal;
	delete rover;
	delete whiskers;

	std::cout << "\n=== WrongAnimal Hierarchy Tests ===" << std::endl;
	const WrongAnimal *wrongGenericAnimal = new WrongAnimal();
	const WrongAnimal *notWhiskers = new WrongCat();
	const WrongCat *specificWrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "Type of wrongGenericAnimal: " << wrongGenericAnimal->getType() << std::endl;
	std::cout << "Type of notWhiskers: " << notWhiskers->getType() << std::endl;
	std::cout << "Type of specificWrongCat: " << specificWrongCat->getType() << std::endl;
	std::cout << std::endl;

	wrongGenericAnimal->makeSound(); // Should output WrongAnimal sound
	notWhiskers->makeSound();		 // Will output WrongAnimal sound due to lack of virtual function
	specificWrongCat->makeSound();	 // Will output WrongCat sound
	std::cout << std::endl;

	delete wrongGenericAnimal;
	delete notWhiskers;
	delete specificWrongCat;

	std::cout << "\n=== Additional Tests ===" << std::endl;

	// Testing array of Animal pointers
	const Animal *animalArray[2];
	animalArray[0] = new Dog();
	animalArray[1] = new Cat();

	for (int i = 0; i < 2; ++i)
	{
		std::cout << "AnimalArray[" << i << "] type: " << animalArray[i]->getType() << std::endl;
		animalArray[i]->makeSound();
	}

	for (int i = 0; i < 2; ++i)
	{
		delete animalArray[i];
	}

	// Testing copy constructor and assignment operator
	std::cout << "\nTesting Copy Constructor and Assignment Operator:" << std::endl;
	Dog originalDog;
	Dog copyDog(originalDog); // Copy constructor
	Dog assignedDog;
	assignedDog = originalDog; // Assignment operator

	Cat originalCat;
	Cat copyCat(originalCat); // Copy constructor
	Cat assignedCat;
	assignedCat = originalCat; // Assignment operator

	std::cout << "\n=== End of Tests ===" << std::endl;

	return 0;
}
