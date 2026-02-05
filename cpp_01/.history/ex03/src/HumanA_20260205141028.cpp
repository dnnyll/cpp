/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:23:22 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/05 14:10:28 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"
#include <iostream>

//	constructor takes reference to Weapon
HumanA::HumanA(const std::string &name, Weapon &weapon)
	: name(name), weapon(weapon) {}

//	destructor
HumanA::~HumanA() {}

//	attack method
void	HumanA::attack() const
{
	std::cout << name << " attacks with their " << weapon.get_type() << std::endl;
}
