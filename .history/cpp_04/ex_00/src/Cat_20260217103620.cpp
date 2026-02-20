/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:35:13 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 10:36:20 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << ": let's high give guys!!" << std::endl;
}

// default constructor
FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap default constructor called for: " << _name << std::endl;
}

//	copy constructor
FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

//	copy assignment operator
FragTrap	&FragTrap::operator=(const FragTrap &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		ClapTrap::operator=(source);	//	calls the ClapTrap class version to copy from
	}
	return (*this);
}

//default destructor
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called for: " << _name << std::endl;
}