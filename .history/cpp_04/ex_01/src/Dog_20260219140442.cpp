/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:04:20 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 14:04:42 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"

//	default constructor
Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "[Dog]\t\tdefault constructor called" << std::endl;
}

//	copy constructor
Dog::Dog(const Dog &copy): Animal(copy)
{
	brain = new Brain()
	std::cout << "[Dog]\t\tcopy constructor called" << std::endl;
}

//	copy assignment operator
Dog	&Dog::operator=(const Dog &source)
{
	std::cout << "[Dog]\t\tcopy assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator=(source);			// copy base members
		delete brain;						// free old Brain
		brain = new Brain(*source.brain);	// deep copy
	}
	return (*this);
}

//default destructor
Dog::~Dog()
{
	delete brain;
	std::cout << "[Dog]\t\tdestructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "============\tWoof\t\t\t\t============" << std::endl;
}

//	set
void Dog::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}

//	get
std::string Dog::getIdea(int index) const
{
	return brain->getIdea(index);
}