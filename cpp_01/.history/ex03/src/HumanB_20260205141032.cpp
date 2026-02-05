/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:26:17 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/05 14:10:32 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/HumanB.hpp"
#include <iostream>

//	constructor weapon
HumanB::HumanB(const std::string &name)
	: name(name), weapon(NULL) {}

//	set weapon
void	HumanB::set_weapon(Weapon &w)
{
	weapon = &w;
}

//	attack method
void HumanB::attack(void) const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->get_type() << std::endl;
	else
		std::cout << name << " has no weapon to attack with" << std::endl;
}