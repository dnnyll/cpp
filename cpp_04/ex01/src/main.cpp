/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/22 19:16:42 by daniefe2         ###   ########.fr       */
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
	const int	nAnimals = 4;

	std::cout << "\n==========\tBASIC POLYMORPHIC TEST\t==========\n" << std::endl;

	std::cout << "\n==========\tCONSTRUCTING\t\t==========\n" << std::endl;

	const Animal	*a = new Dog();
	const Animal	*b = new Cat();
	
	std::cout << "\n==========\tDESTROYING\t\t==========\n" << std::endl;

	delete a;
	delete b;

	std::cout << "\n==========\tARRAY OF ANIMALS\t==========\n" << std::endl;

	Animal	**animals = new Animal*[nAnimals];
	int	iAnimals = 0;
	
	while (iAnimals < nAnimals)
	{
		if (iAnimals < nAnimals / 2)
			animals[iAnimals] = new Dog();
		else
			animals[iAnimals] = new Cat();
		iAnimals++;
	}

	std::cout << "\n==========\tSETTING IDEAS\t\t==========\n" << std::endl;

	animals[0]->setIdea(0, "Dogs worship humans.");
	animals[1]->setIdea(0, "Dogs like bones.");
	animals[2]->setIdea(0, "Cats tolerate humans.");
	animals[3]->setIdea(0, "Cats like fish.");

	std::cout << "\n==========\tREADING IDEAS\t\t==========\n" << std::endl;

	iAnimals = 0;
	while (iAnimals < nAnimals)
	{
		std::cout	<< animals[iAnimals]->getType()
					<< " idea: "
					<< animals[iAnimals]->getIdea(0)
					<< std::endl;
		iAnimals++;
	}

	std::cout << "\n==========\tARRAY CLEANUP\t\t\t==========\n" << std::endl;

	iAnimals = 0;
	while (iAnimals < nAnimals)
	{
		delete animals[iAnimals];
		iAnimals++;
	}
	delete[] animals;

	std::cout << "\n==========\tDEEP COPY TEST\t\t==========\n" << std::endl;

	std::cout << "\n==========\tTEST 1\t\t\t==========\n" << std::endl;

	Dog	a1;
	Dog	b1(a1);
	std::cout << std::endl;
	a1.setIdea(0, "A");
	std::cout << "result a1:\t" << a1.getIdea(0) << std::endl;
	std::cout << "result b1:\t" << b1.getIdea(0) << std::endl;

	b1.setIdea(0, "B");
	std::cout << "result a1:\t" << a1.getIdea(0) << std::endl;
	std::cout << "result b1:\t" << b1.getIdea(0) << std::endl;
	std::cout << std::endl;
	std::cout << "note: the objects do not share the same Brain" << std::endl;

	std::cout << "\n==========\tTEST 2\t\t\t==========\n" << std::endl;
	
	Dog	original;
	original.setIdea(0, "Original dog idea.");

	Dog	copy(original);

	std::cout << std::endl;
	std::cout << "Before modification:" << std::endl;
	std::cout << "Original: " << original.getIdea(0) << std::endl;
	std::cout << "Copy:     " << copy.getIdea(0) << std::endl;

	copy.setIdea(0, "Modified copy idea.");

	std::cout << "\nAfter modification:" << std::endl;
	std::cout << "Original: " << original.getIdea(0) << std::endl;
	std::cout << "Copy:     " << copy.getIdea(0) << std::endl;
	std::cout << std::endl;

	return (0);
}
