/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:02:24 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 13:27:12 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	set_name

//	constructor
Zombie::Zombie(std::string name): name(name){}

//	destructor
Zombie::~Zombie(void)
{
	std::cout << name << ": has been wiped." << std::endl;
}