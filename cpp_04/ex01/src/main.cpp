/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/21 12:54:52 by daniefe2         ###   ########.fr       */
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
	int	n = 4;

	std::cout << "\n========== BASIC POLYMORPHIC DELETION TEST ==========\n" << std::endl;

	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	delete j;
	delete i;

	std::cout << "\n========== ARRAY OF ANIMALS ==========\n" << std::endl;

	Animal	**animals = new Animal*[n];

	int	iAnimals = 0;
	while (iAnimals < n)
	{
		if (iAnimals < n / 2)
			animals[iAnimals] = new Dog();
		else
			animals[iAnimals] = new Cat();
		iAnimals++;
	}

	std::cout << "\n========== SETTING IDEAS ==========\n" << std::endl;

	animals[0]->setIdea(0, "Dogs worship humans.");
	animals[1]->setIdea(0, "Dogs like bones.");
	animals[2]->setIdea(0, "Cats tolerate humans.");
	animals[3]->setIdea(0, "Cats like fish.");

	std::cout << "\n========== READING IDEAS ==========\n" << std::endl;

	iAnimals = 0;
	while (iAnimals < n)
	{
		std::cout	<< animals[iAnimals]->getType()
					<< " idea: "
					<< animals[iAnimals]->getIdea(0)
					<< std::endl;
		iAnimals++;
	}

	std::cout << "\n========== DEEP COPY TEST ==========\n" << std::endl;

	Dog	original;
	original.setIdea(0, "Original dog idea.");

	Dog	copy(original);

	std::cout << "Before modification:" << std::endl;
	std::cout << "Original: " << original.getIdea(0) << std::endl;
	std::cout << "Copy:     " << copy.getIdea(0) << std::endl;

	copy.setIdea(0, "Modified copy idea.");

	std::cout << "\nAfter modification:" << std::endl;
	std::cout << "Original: " << original.getIdea(0) << std::endl;
	std::cout << "Copy:     " << copy.getIdea(0) << std::endl;

	std::cout << "\n========== CLEANUP ==========\n" << std::endl;

	iAnimals = 0;
	while (iAnimals < n)
	{
		delete animals[iAnimals];
		iAnimals++;
	}

	delete[] animals;

	return 0;
}












// int main()
// {
// 	int		nAnimals = 2;
// 	int		iAnimals = 0;
// 	int		jAnimals = 0;
// 	Animal	*animals[nAnimals];
	
// 	std::cout << "============\tCREATING ANIMALS\t\t============\n" << std::endl;
// 	//	first half are cats
// 	while (iAnimals < nAnimals / 2)
// 	{
// 		animals[iAnimals] = new Cat();
// 		animals[iAnimals]->makeSound();
// 		iAnimals++;
// 	}
// 	jAnimals = iAnimals;

// 	while (jAnimals < nAnimals)
// 	{
// 		animals[jAnimals] = new Dog();
// 		animals[jAnimals]->makeSound();
// 		jAnimals++;
// 	}
	
// 	// std::cout << "============\tSETTING IDEAS\t============\n" << std::endl;
// 	// iAnimals = 0;
// 	// while (iAnimals < nAnimals)
// 	// {
// 	// 	std::string type = animals[iAnimals]->getType();

// 	// 	std::cout << "[DEBUG] Setting ideas for " << type
// 	// 			<< " at index " << iAnimals << std::endl;

// 	// 	if (type == "Cat")
// 	// 	{
// 	// 		animals[iAnimals]->setIdea(0, "I am cool therefore humans feed me..");
// 	// 		std::cout << "[DEBUG] Cat idea[0] set" << std::endl;
// 	// 	}
// 	// 	else if (type == "Dog")
// 	// 	{
// 	// 		animals[iAnimals]->setIdea(0, "Humans are cool because they feed me..");
// 	// 		std::cout << "[DEBUG] Dog idea[0] set" << std::endl;
// 	// 	}

// 	// 	iAnimals++;
// 	// }
// 	// std::cout << "[DEBUG] Finished setting ideas for all animals\n" << std::endl;

// 	std::cout << "\n============\tSETTING IDEAS\t============\n" << std::endl;

// 	iAnimals = 0;

// 	while (iAnimals < nAnimals)
// 	{
// 		std::string	type = animals[iAnimals]->getType();
// 		if (type == "Cat")
// 			animals[iAnimals]->setIdea(0, "I am cool therefore humans feed me..");
// 		else if (type == "Dog")
// 			animals[iAnimals]->setIdea(0, "Humans are cool because they feed me..");
// 		iAnimals++;
// 	}

// 	std::cout << "============\tPRINTING IDEAS\t============\n" << std::endl;
	
// 	iAnimals = 0;
	
// 	while (iAnimals < nAnimals)
// 	{
// 		std::string type = animals[iAnimals]->getType();
// 		std::cout << type << " idea[0]:\t" << animals[iAnimals]->getIdea(0) << std::endl;
// 		iAnimals++;
// 	}
	
// 	std::cout << "\n============\tSETTING IDEAS\t============\n" << std::endl;
	
// 	iAnimals = 0;
	
// 	while (iAnimals < nAnimals)
// 	{
// 		std::string	type = animals[iAnimals]->getType();
// 		animals[iAnimals]->setIdea(0, type == "Cat" ? "Feed me NOW!" : "Please feed me!");
// 		animals[iAnimals]->setIdea(1, type == "Cat" ? "I am the best." : "You are the best!");
// 		iAnimals++;
// 	}
	
// 	std::cout << "============\tPRINTING IDEAS\t============\n" << std::endl;
	
// 	iAnimals = 0;
// 	while (iAnimals < nAnimals)
// 	{
// 		std::string type = animals[iAnimals]->getType();
// 		std::cout << type << " idea[0]:\t" << animals[iAnimals]->getIdea(0) << std::endl;
// 		std::cout << type << " idea[1]:\t" << animals[iAnimals]->getIdea(1) << std::endl;
// 		iAnimals++;
// 	}

// 	std::cout << "\n============\tDELETING ANIMALS\t============\n" << std::endl;

// 	iAnimals = 0;

// 	while (iAnimals < nAnimals)
// 	{
// 		delete animals[iAnimals];
// 		iAnimals++;
// 	}

// 	std::cout << "\n============\tDEEP COPY TEST\t============\n" << std::endl;

// 	Cat	originalCat;
// 	originalCat.setIdea(0, "avoid water");
// 	//	can I build a new Cat correctly from another Cat?
// 	Cat	copyCat = originalCat;			// call copy constructor
// 	copyCat.setIdea(0, "manipulate humans");

// 	std::cout << "============\torig idea[0]: " << originalCat.getIdea(0) << std::endl;
// 	std::cout << "============\tcopy idea[0]: " << copyCat.getIdea(0) << std::endl;

// 	std::cout << " " << std::endl;

// 	Dog	originalDog;
// 	originalDog.setIdea(0, "dig a hole");
// 	//	can I safely replace the contents of an existing Dog?
// 	Dog	copyDog;
// 	copyDog = originalDog;				// call assignment operator
// 	copyDog.setIdea(0, "worship humans");

// 	std::cout << "============\torig idea[0]: " << originalDog.getIdea(0) << std::endl;
// 	std::cout << "============\tcopy idea[0]: " << copyDog.getIdea(0) << std::endl;

// 	std::cout << "\n============\tTEST ENDING\t\t============\n" << std::endl;

// 	return (0);
// }

/*
	notes:
	
	-	If a class is meant to be polymorphic, its destructor must be virtual.
*/