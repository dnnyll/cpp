/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 12:02:42 by daniefe2         ###   ########.fr       */
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
	int		nAnimals = 4;
	int		iAnimals = 0;
	int		jAnimals = 0;
	Animal	*animals[nAnimals];
	
	std::cout << "============\tCREATING ANIMALS\t\t============\n" << std::endl;
	//	first half are cats
	while (iAnimals < nAnimals / 2)
	{
		animals[iAnimals] = new Cat();
		animals[iAnimals]->makeSound();
		iAnimals++;
	}
	jAnimals = iAnimals;
	//	second half are dogs
	while (jAnimals < nAnimals)
	{
		animals[jAnimals] = new Dog();
		animals[jAnimals]->makeSound();
		jAnimals++;
	}
	
	std::cout << "============\tSETTING IDEAS\t============\n" << std::endl;

	iAnimals = 0;

	while (iAnimals < nAnimals)
	{
		std::string type = animals[iAnimals]->getType();
		if (type == "Cat")
			animals[iAnimals]->setIdea(0, "I am cool therefore humans feed me..");
		else if (type == "Dog")
			animals[iAnimals]->setIdea(0, "Humans are cool because they feed me..");
		iAnimals++;
	}
	iAnimals = 0;
	while (iAnimals < nAnimals)
	{
		animals[iAnimals]->setIdea(0, type == "Cat" ? "Feed me NOW!" : "Please feed me!");
		animals[iAnimals]->setIdea(1, type == "Cat" ? "I am the best." : "Chase the ball");

	}
	

	return (0);
}
