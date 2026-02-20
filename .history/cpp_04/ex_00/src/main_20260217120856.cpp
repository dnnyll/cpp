/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 12:08:56 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main()
{
	const Animal	*animal = new Animal();
	animal->makeSound();
	delete animal;
	std::cout << "============================================================" << std::endl;

	const Animal	*cat = new Cat();
	animal->makeSound();
	delete cat;
	std::cout << "============================================================" << std::endl;

	const Animal	*dog = new Dog();
	animal->makeSound();
	delete dog;
	std::cout << "============================================================" << std::endl;
	
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	animal->makeSound();
	delete wrongAnimal;
	std::cout << "============================================================" << std::endl;
	
	const WrongAnimal	*wrongCat = new WrongAnimal();
	animal->makeSound();
	delete wrongAnimal;
	std::cout << "============================================================" << std::endl;
	
	// const Animal* i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();

	// delete meta;
	// delete j;
	// delete i;
	return (0);
}
