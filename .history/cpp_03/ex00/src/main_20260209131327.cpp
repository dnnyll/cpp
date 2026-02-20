/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 13:13:27 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ClapTrap.hpp"

int	main(void)
{
	std::cout << "Launching ClapTrap Tournament..." << std::endl;
	std::cout << "Constructing constestents..." << std::endl;

	ClapTrap	Original("OG");
	ClapTrap	Clone("Clone");

	std::cout << "Engaging in combat..." << std::endl;

	// Original.attack("Clone");
	// Clone.takeDamage(1);
	// Clone.beRepaired(11);
	// Clone.beRepaired(11);
	// Clone.attack("OG");
	
	Original.attack("Clone");
	Clone.takeDamage(5);
	Clone.beRepaired(1);
	Clone.attack("Original");
	Original.takeDamage(3);
	Original.attack("Clone");
	Clone.takeDamage(7);
	Clone.beRepaired(3);
	Clone.attack("Clone");
	
	std::cout << "Battle concluded..." <<std::endl;
	return (0);
}