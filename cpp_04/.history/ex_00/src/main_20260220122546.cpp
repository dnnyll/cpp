/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/20 12:25:46 by daniefe2         ###   ########.fr       */
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

	/*
		static binding (compile-time)
		
		c++ decides which function to call at compile time.
		it looks only at the pointer type, not the actual object type.
		pointer type = WrongAnimal* → function chosen = WrongAnimal::makeSound()
		
		if the base class had declared the function virtual: virtual void makeSound();
		C++ would create a vtable (virtual table) for dynamic dispatch.
		then calling wrongCatBase->makeSound() would execute WrongCat::makeSound()
		this is runtime polymorphism.

		static binding ignores the derived override when using a base class pointer.
		=========== some generic animal sound ============
	*/

	return (0);
}
