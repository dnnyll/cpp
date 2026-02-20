/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:12:50 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 10:55:15 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"

// default constructor
Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	type = "Animal";
}

// copy constructor
Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

// assignment operator
Animal &Animal::operator=(const Animal &source)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &source)
		type = source.type;
	return *this;
}

// destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

// default sound
void Animal::makeSound() const
{
	std::cout << "Some generic animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}
