/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:00:26 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 12:34:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <../inc/ClapTrap.hpp>

// default constructor
ClapTrap::ClapTrap():	_name("default"),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

//	copy constructor
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

//	copy assignment operator
ClapTrap	&ClapTrap::operator=(const ClapTrap &source)
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
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for: " << _name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout	<< "ClapTrap" << _name
					<< " is already destroyed."
					<< std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout	<< "ClapTrap " << _name
					<< " energy is depleted."
					<< std::endl;
		return ;
	}
	std::cout	<< "ClapTrap "	<< _name
				<< " attacks "	<< target
				<< ", causing "	<< _attackDamage
				<< " points of damage!"	<< std::endl;
	_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout	<< "ClapTrap" << _name
					<< " is already destroyed."
					<< std::endl;
		return ;
	}
	if ((int)amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	
	std::cout 	<< "ClapTrap"	<< _name
				<< " takes "	<< amount
				<< " points of damage.\n"
				<< "Current HP: " << _hitPoints
				<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 10)
		std::cout	<< "ClapTrap" << _name
					<< "is already fully repaired"
					<< std::endl;
	if ((int)amount >= _hitPoints)
		_hitPoints = 10;
	else
		_hitPoints += amount;
	std::cout	<< "ClapTrap"	<< _name
				<< " repairs itself for " << amount
				<< " life points.\n"
				<< "Current HP: "	<< _hitPoints
				<< std::endl;
	_energyPoints--;
}