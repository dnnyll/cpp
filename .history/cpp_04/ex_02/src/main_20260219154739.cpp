/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:12:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 15:47:39 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    Animal* animals[2];
    int iAnimals = 0;
    const int nAnimals = 2;

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

    std::cout << "\n============\tDEEP COPY TEST (CAT)\t============\n" << std::endl;

    Cat originalCat;
    originalCat.setIdea(0, "avoid water");

    Cat copyCat = originalCat;
    copyCat.setIdea(0, "manipulate humans");

    std::cout << "orig idea[0]: " << originalCat.getIdea(0) << std::endl;
    std::cout << "copy idea[0]: " << copyCat.getIdea(0) << std::endl;

    std::cout << "\n============\tDELETING ANIMALS\t============\n" << std::endl;

    iAnimals = 0;
    while (iAnimals < nAnimals)
    {
        delete animals[iAnimals];
        iAnimals++;
    }

    return 0;
}
