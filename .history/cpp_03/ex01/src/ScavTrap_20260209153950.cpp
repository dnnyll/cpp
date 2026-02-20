/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:23:37 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 15:39:50 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ScavTrap.hpp"

// default constructor
ScavTrap::ScavTrap(const std::string &_name): ClapTrap(_name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}
void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gatekeeper mode." << std::endl;
}