/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:12:50 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/21 18:07:58 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"

// default constructor
Animal::Animal()
{
	std::cout << "[Animal]\tdefault constructor called" << std::endl;
	type = "Animal";
}

// copy constructor
Animal::Animal(const Animal &copy)
{
	std::cout << "[Animal]\tcopy constructor called" << std::endl;
	*this = copy;
}

// copy assignment operator
Animal	&Animal::operator=(const Animal &source)
{
	std::cout << "[Animal]\tcopy assignment operator called" << std::endl;
	if (this != &source)
		type = source.type;
	return (*this);
}

// destructor
Animal::~Animal()
{
	std::cout << "[Animal]\tdestructor called" << std::endl;
}

// default sound
void	Animal::makeSound() const
{
	std::cout << "============\tsome generic animal sound\t============" << std::endl;
}

//	getType
std::string Animal::getType() const
{
	return (type);
}

//	the following functions are not necessary if we declare their value as NULL in the Animal class
//	for the purpose of the exercise we will do it this way
void	Animal::setIdea(int index, const std::string& idea)
{
	(void)index;
	(void)idea;
}
std::string	Animal::getIdea(int index) const
{
	(void)index;
	return "";
}