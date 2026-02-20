/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 12:01:05 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ClapTrap.hpp"

int	main(void)
{
	std::cout << "\nLaunching ClapTrap Tournament..." << std::endl;
	std::cout << "Constructing constestents...\n" << std::endl;

	ClapTrap	Original("OG");
	ClapTrap	Clone("Clone");

	std::cout << "\nEngaging in combat...\n" << std::endl;


	Original.attack("Clone");
	Clone.takeDamage(0);
	Clone.attack("OG");
	Original
	// no energy test
	// Original.attack("Clone");
	// Clone.takeDamage(0);
	// Clone.beRepaired(1);
	// Clone.beRepaired(1);
	// Clone.beRepaired(1);
	// Clone.beRepaired(1);
	// Clone.beRepaired(1);
	// Clone.beRepaired(1);
	// Clone.beRepaired(1);
	// Clone.beRepaired(1);
	// Clone.beRepaired(1);
	// Clone.beRepaired(1);
	// Clone.attack("OG");
	// Clone.beRepaired(1);

	std::cout << "\nBattle concluded...\n" <<std::endl;

	//	dead test
	// Original.attack("Clone");
	// Clone.takeDamage(5);
	// Clone.beRepaired(1);
	// Clone.attack("OG");
	// Original.takeDamage(3);
	// Original.attack("Clone");
	// Clone.takeDamage(7);
	// Clone.beRepaired(3);
	// Clone.attack("Clone");
	
	std::cout << "\nBattle concluded...\n" <<std::endl;
	return (0);
}