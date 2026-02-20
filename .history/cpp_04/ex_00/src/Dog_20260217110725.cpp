/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:04:20 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 11:07:25 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "../inc/Animal.hpp"
#include ""

// default constructor
Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

//	copy constructor
Dog::Dog(const Dog &copy): Animal(copy)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

//	copy assignment operator
Dog	&Dog::operator=(const Dog &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator=(source);
	}
	return (*this);
}

//default destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Meow" << std::endl;
}