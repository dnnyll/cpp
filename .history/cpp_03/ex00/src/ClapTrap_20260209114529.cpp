/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:00:26 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 11:45:29 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <../inc/ClapTrap.hpp>

// Constructors
ClapTrap::ClapTrap(): _name("default"), _hit_pts(10), _energy_pts(10), _attack_dmg(0)
{
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}
ClapTrap::Claptrap()
{
	std::cout << "contructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "copy contrusctor called" << std::endl;
}
ClapTrap	&ClapTrap::operator=(const ClapTrap &source);	//	copy assignment operator
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
	{
		this->name = source.name;
		this->hitPoints = source.hitPoints;
		this->energyPoints = source.energyPoints;
		this->attackDamage = source.attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout	<< "ClapTrap" << name
					<< " is already destroyed."
					<< std::endl;
		return ;
	}
	if (energyPoints == 0)
	{
		std::cout	<< "ClapTrap" << name
					<< " energy is depleted."
					<< std::endl;
		return ;
	}
	std::cout	<< "ClapTrap"	<< name
				<< "attacks"	<< target
				<< ", causing"	<< attackDamage
				<< "points of damage!"	<< std::endl;
	energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout	<< "ClapTrap" << name
					<< " is already destroyed."
					<< std::endl;
		return ;
	}
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	
	std::cout 	<< "ClapTrap"	<< name
				<< " takes "	<< amount
				<< " points of damage.\n"
				<< "Current HP: " << hitPoints
				<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 10)
		std::cout	<< "ClapTrap" << name
					<< "is already fully repaired"
					<< std::endl;
	if (amount >= hitPoints)
		hitPoints = 10;
	else
		hitPoints += amount;
	std::cout	<< "ClapTrap"	<< name
				<< " repairs itself for " << amount
				<< "life points.\n"
				<< "Current HP: "	<< hitPoints
				<< std::endl;
	energyPoints--;
}