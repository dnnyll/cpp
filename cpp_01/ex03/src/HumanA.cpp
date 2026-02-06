/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:23:22 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/06 14:54:44 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/HumanA.hpp"

//	constructor
//	always has a weapon passed as argument
HumanA::HumanA(const std::string &name, Weapon &weapon):
	name(name), weapon(weapon) {}

//	destructor
HumanA::~HumanA() {}

//	attack method
void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
