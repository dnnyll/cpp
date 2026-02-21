/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:57:12 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/21 18:07:20 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

// default constructor
WrongCat::WrongCat()
{
	std::cout << "[WrongCat]\tdefault constructor called" << std::endl;
	type = "WrongCat";
}

//	copy constructor
WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
	std::cout << "[WrongCat]\t\tcopy constructor called" << std::endl;
}

//	copy assignment operator
WrongCat	&WrongCat::operator=(const WrongCat &source)
{
	std::cout << "[WrongCat]\t\tcopy assignment operator called" << std::endl;
	if (this != &source)
	{
		WrongAnimal::operator=(source);
	}
	return (*this);
}

//default destructor
WrongCat::~WrongCat()
{
	std::cout << "[WrongCat]\tdestructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "============\tMeow\t\t\t\t============" << std::endl;
}