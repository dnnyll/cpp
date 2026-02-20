/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 12:22:21 by daniefe2         ###   ########.fr       */
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
	cat->makeSound();
	delete cat;
	std::cout << "============================================================" << std::endl;

	const Animal	*dog = new Dog();
	dog->makeSound();
	delete dog;
	std::cout << "============================================================" << std::endl;
	
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	wrongAnimal->makeSound();
	delete wrongAnimal;
	std::cout << "============================================================" << std::endl;
	
	const WrongCat	*wrongCat = new WrongCat();
	wrongCat->makeSound();
	delete wrongCat;
	std::cout << "============================================================" << std::endl;
	
	const WrongAnimal	*messedUp = new WrongCat();
	messedUp->makeSound();

	
	return (0);
}
