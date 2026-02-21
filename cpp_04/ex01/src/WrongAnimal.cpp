/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:50:37 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/21 18:08:18 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/WrongAnimal.hpp"

// default constructor
WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal]\tdefault constructor called" << std::endl;
	type = "WrongAnimal";
}

// copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "[WrongAnimal]\tcopy constructor called" << std::endl;
	*this = copy;
}

// copy assignment operator
WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &source)
{
	std::cout << "[WrongAnimal]\tcopy assignment operator called" << std::endl;
	if (this != &source)
		type = source.type;
	return (*this);
}

// destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal]\tdestructor called" << std::endl;
}

// default sound
void	WrongAnimal::makeSound() const
{
	std::cout << "============\tsome generic animal sound\t============" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
