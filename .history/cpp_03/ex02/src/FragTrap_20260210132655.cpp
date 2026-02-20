/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:24:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 13:26:55 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/FragTrap.hpp"
#include "../inc/ClapTrap.hpp"


void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " is now in Gatekeeper mode" << std::endl;
}

// default constructor
FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

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

void	FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout	<< "FragTrap " << _name
					<< " cannot attack because it's destroyed"
					<< std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout	<< "FragTrap " << _name
					<< " cannot attack because it's energy is depleted"
					<< std::endl;
		return ;
	}
	_energyPoints--;
	std::cout	<< "FragTrap "	<< _name
				<< " attacks "	<< target
				<< " dealing " << _attackDamage
				<< "\n"
				<< "ClapTrap " << _name
				<< " energy points left : " << _energyPoints
				<< std::endl;
}

