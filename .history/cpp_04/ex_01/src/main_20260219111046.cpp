/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 11:10:46 by daniefe2         ###   ########.fr       */
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
	int		nAnimals;
	int		iAnimals;
	int		jAnimals;
	Animal	*animals[nAnimals];

	nAnimals = 2;
	iAnimals = 0;
	
	std::cout << "============\tCREATING ANIMALS\t\t============\n" << std::endl;
	while (iAnimals < nAnimals / 2)
	{
		animals[iAnimals] = new Cat();
		animals[iAnimals]->makeSound();
		iAnimals++;
	}
	jAnimals = iAnimals;
	while (jAnimals < nAnimals)
	{
		animals[jAnimals] = new Cat();
		animals[jAnimals]->makeSound();
		jAnimals++;
	}


	
	std::cout << "============\tANIMAL POLYMORPHISM\t\t============\n" << std::endl;
	const Animal	*animal = new Animal();
	animal->makeSound();			//	generic Animal
	delete animal;
	std::cout << "============================================================" << std::endl;

	const Animal	*cat = new Cat();
	cat->makeSound();
	delete cat;						//	Meow
	std::cout << "============================================================" << std::endl;

	const Animal	*dog = new Dog();
	dog->makeSound();
	delete dog;						//	Woof
	std::cout << "============================================================\n" << std::endl;
	
	
	std::cout << "============\tWRONGANIMAL POLYMORPHISM\t============\n" << std::endl;
	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	wrongAnimal->makeSound();		//	generic WrongAnimal
	delete wrongAnimal;
	std::cout << "============================================================" << std::endl;
	
	const WrongCat	*wrongCatDirect = new WrongCat();
	wrongCatDirect->makeSound();	//	calls WrongCat::makeSound		(direct pointer)
	delete wrongCatDirect;
	std::cout << "============================================================" << std::endl;
	
	const WrongAnimal	*wrongCatBase = new WrongCat();
	wrongCatBase->makeSound();		//	calls WrongAnimal::makeSound	(base pointer)
	delete wrongCatBase;
	std::cout << "============================================================\n" << std::endl;

	return (0);
}
