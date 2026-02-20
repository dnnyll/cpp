/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:12:50 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 10:20:36 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "..inc/Aanimal.hpp"

//	default constructor
Animal::Animal(const std::string &inputName)
{
	std::cout << "" << std::endl;
}

//	copy constructor
Animal::Animal(const Animal &copy)
{
	std::cout << "cpy cnstrctr" << std::endl;
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
	std::cout << "dstrctr" << _name << std::endl;
}