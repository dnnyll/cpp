/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:35:13 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 11:33:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"

// default constructor
Cat::Cat()
{
	type = "Cat";
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
	std::cout << "[Cat]\t\tassignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator=(source);
	}
	return (*this);
}

//default destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}