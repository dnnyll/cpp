/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:35:13 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 10:36:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


void	Cat::highFivesGuys(void)
{
	std::cout << "Cat " << _name << ": let's high give guys!!" << std::endl;
}

// default constructor
Cat::Cat(const std::string &name): Animal(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "Cat default constructor called for: " << _name << std::endl;
}

//	copy constructor
Cat::Cat(const Cat &copy): Animal(copy)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

//	copy assignment operator
Cat	&Cat::operator=(const Cat &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		Animal::operator=(source);	//	calls the Animal class version to copy from
	}
	return (*this);
}

//default destructor
Cat::~Cat()
{
	std::cout << "Cat " << _name << " destructor called for: " << _name << std::endl;
}