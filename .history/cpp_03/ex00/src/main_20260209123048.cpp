/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 12:30:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "inc/ClapTrap.hpp"

int	main(void)
{
	std::cout << "Launching ClapTrap Tournament..." << std::endl;
	std::cout << "Constructing constestents..." << std::endl;

	ClapTrap	Original;
	ClapTrap	Clone;

	std::cout << "Engaging in combat..." << std::endl;
	Original.attack("Clone");
	Clone.takeDamage(5);
	Clone.beRepaired(1);
	Clone.attack("Original");
	Original.takeDamage(3);
	Original.attack("Clone");
	Clone.takeDamage(7);
	
	return (0);
}