/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:23:37 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 16:21:28 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ScavTrap.hpp"
#include "../inc/ClapTrap.hpp"

// default constructor
ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

//	copy constructor
ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(_name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

//	copy assignment operator
ScavTrap	&ScavTrap::operator=(const ScavTrap &source): ClapTrap(_name)
{
	
}
//default destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << "is now in Gatekeeper mode." << std::endl;
}

