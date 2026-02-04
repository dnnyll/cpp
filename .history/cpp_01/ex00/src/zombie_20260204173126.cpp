/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:02:24 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/04 17:31:26 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inczombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//	constructor
Zombie::Zombie(std::string name): name(name){}

//	destructor
Zombie::~Zombie(void)
{
	std::cout << name << ": has been wiped." << std::endl;
}