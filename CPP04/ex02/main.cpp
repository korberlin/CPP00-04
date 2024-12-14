/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkoksal <gkoksal@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:32:52 by gkoksal           #+#    #+#             */
/*   Updated: 2024/11/06 10:32:53 by gkoksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
	// Animal animal; // Error: Cannot instantiate abstract class

	Animal *dog = new Dog();
	Animal *cat = new Cat();

	dog->makeSound(); // Outputs "Woof! Woof!"
	cat->makeSound(); // Outputs "Meow! Meow!"

	delete dog;
	delete cat;

	return 0;
}
