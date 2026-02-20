/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 15:52:32 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int	main()
{
	Animal		*animals[2];
	int			iAnimals = 0;
	const int	nAnimals = 2;

	Animal	turtle;
	std::cout << "\n============\tCREATING ANIMALS\t============\n" << std::endl;

	// Create Dog and Cat dynamically
	iAnimals = 0;
	while (iAnimals < nAnimals)
	{
		if (iAnimals == 0)
			animals[iAnimals] = new Dog();
		else
			animals[iAnimals] = new Cat();
		iAnimals++;
	}

	std::cout << "\n============\tMAKING SOUNDS\t============\n" << std::endl;

	iAnimals = 0;
	while (iAnimals < nAnimals)
	{
		animals[iAnimals]->makeSound();
		iAnimals++;
	}

	std::cout << "\n============\tDEEP COPY TEST\t============\n" << std::endl;

	Cat originalCat;
	originalCat.setIdea(0, "avoid water");

	Cat copyCat = originalCat;
	copyCat.setIdea(0, "manipulate humans");

	std::cout << "orig idea[0]:\t" << originalCat.getIdea(0) << std::endl;
	std::cout << "copy idea[0]:\t" << copyCat.getIdea(0) << std::endl;

	std::cout << "\n============\tDELETING ANIMALS\t============\n" << std::endl;

	iAnimals = 0;
	while (iAnimals < nAnimals)
	{
		delete animals[iAnimals];
		iAnimals++;
	}

	return (0);
}
