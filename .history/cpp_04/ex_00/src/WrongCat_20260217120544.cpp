/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:57:12 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 12:05:44 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

// default constructor
WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "[WrongCat]\t\tdefault constructor called" << std::endl;
}

//	copy constructor
WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
	std::cout << "[WrongCat]\t\tcopy constructor called" << std::endl;
}

//	copy assignment operator
WrongCat	&WrongCat::operator=(const WrongCat &source)
{
	std::cout << "[WrongCat]\t\tassignment operator called" << std::endl;
	if (this != &source)
	{
		WrongAnimal::operator=(source);
	}
	return (*this);
}

//default destructor
WrongCat::~WrongCat()
{
	std::cout << "[WrongCat]\t\tdestructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "============\tMeow\t\t\t\t============" << std::endl;
}