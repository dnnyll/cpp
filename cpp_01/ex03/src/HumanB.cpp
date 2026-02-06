/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:26:17 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/06 15:01:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/HumanB.hpp"

//	constructor
//	doesn't have a weapon, set to NULL
HumanB::HumanB(const std::string &name):
	name(name), weapon(NULL) {}

//	set weapon
void	HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

//	attack method
void HumanB::attack(void) const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " has no weapon to attack with" << std::endl;
}