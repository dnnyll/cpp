/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 14:48:46 by daniefe2         ###   ########.fr       */
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

/*

const WrongAnimal *wrongCatBase = new WrongCat();


wrongCatBase->makeSound();
	
	the compiler only looks at the functions declared in WrongAnimal.
	it does not know about the functions or members declared only in WrongCat.
		
	if makeSound() is virtual, the compiler will allow dynamic dispatch to the derived function.
	if makeSound() is non-virtual, it will call the base class function (WrongAnimal) even though the actual object is WrongCat.
*/
