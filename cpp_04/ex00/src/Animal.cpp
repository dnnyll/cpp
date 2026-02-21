/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:12:50 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/21 18:07:02 by daniefe2         ###   ########.fr       */
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

std::string Animal::getType() const
{
	return (type);
}
