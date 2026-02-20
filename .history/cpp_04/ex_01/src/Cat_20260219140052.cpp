/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:35:13 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 14:00:52 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"

// default constructor
Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "[Cat]\t\tdefault constructor called" << std::endl;
}

//	copy constructor
Cat::Cat(const Cat &copy): Animal(copy)
{
	std::cout << "[Cat]\t\tcopy constructor called" << std::endl;
}

//	copy assignment operator
Cat	&Cat::operator=(const Cat &source)
{
	std::cout << "[Cat]\t\tcopy assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator=(source);
		Animal::operator=(other);     // copy base members
        delete brain;                 // free old Brain
        brain = new Brain(*other.brain); // deep copy
	}
	return (*this);
}

//	default destructor
Cat::~Cat()
{
	delete brain;
	std::cout << "[Cat]\t\tdestructor called" << std::endl;
}

//	print function
void	Cat::makeSound() const
{
	std::cout << "============\tMeow\t\t\t\t============" << std::endl;
}

//	set
void Cat::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

//	get
std::string Cat::getIdea(int index) const
{
	return brain->getIdea(index);
}
