/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:12:50 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 10:23:56 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Animal.hpp"

//	default constructor
Animal::Animal(const std::string &inputName)
{
	std::cout << "Animal default constructor called" << std::endl;
}

//	copy constructor
Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = copy;
}

//	copy assignment operator
Animal	&Animal::operator=(const Animal &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->_name = source._name;
		this->_hitPoints = source._hitPoints;
		this->_energyPoints = source._energyPoints;
		this->_attackDamage = source._attackDamage;
	}
	return (*this);
}

//	default destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called for: " << _name << std::endl;
}