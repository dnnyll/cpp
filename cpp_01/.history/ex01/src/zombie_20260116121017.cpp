/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:02:24 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 12:10:17 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"
#include <zombie_20260116113935.hpp>

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(const std::string &input_name)
{
	name = input_name;
}

//	constructor
Zombie::Zombie() : name("") {}
Zombie::Zombie(std::string name) : name(name) {}

//	destructor
Zombie::~Zombie(void)
{
	std::cout << name << ": has been wiped." << std::endl;
}