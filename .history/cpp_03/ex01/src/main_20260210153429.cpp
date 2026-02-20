/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 15:34:29 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main(void)
{
		std::cout << "\nLaunching ClapTrap Tournament..." << std::endl;
	
	//	Regular combat
	{
		std::cout << "Constructing constestents...\n" << std::endl;
		
		ClapTrap	OG("OG");
		ClapTrap	CP("CP");
		
		std::cout << "\nRegular attack test\t\t======------\n" << std::endl;
		OG.attack("CP");
		CP.takeDamage(0);
		CP.attack("OG");
		OG.takeDamage(0);

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;

	//	Combat with different takeDamage values + repair max hitpoints
	{
		std::cout << "Constructing constestents...\n" << std::endl;

		ClapTrap	OG("OG");
		ClapTrap	CP("CP");

		std::cout << "\nDifferent takeDamage test\t======------\n" << std::endl;
		
		OG.attack("CP");
		CP.takeDamage(4);
		CP.beRepaired(2);
		CP.beRepaired(3);

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;

	//	Combat estroyed
	{
		std::cout << "Constructing constestents...\n" << std::endl;

		ClapTrap	OG("OG");
		ClapTrap	CP("CP");

		std::cout << "\nDestroyed test\t======------\n" << std::endl;

		CP.attack("OG");
		OG.takeDamage(0);
		CP.attack("OG");
		OG.takeDamage(0);
		OG.attack("CP");
		CP.takeDamage(20);
		CP.beRepaired(10);
		CP.attack("OG");

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;

//////////////////////////////////////////////////////////////////////////////////////

	std::cout << "\nLaunching ClapTrap Tournament..." << std::endl;
	{
		std::cout << "Constructing constestents...\n" << std::endl;
		
		// ClapTrap	CT("CT");
		// ScavTrap	ST("ST");
		ScavTrap	ST_1("ST_1");
		ScavTrap	ST_2("ST_2");
		
		std::cout << "\nEngaging in combat...\n" << std::endl;

		ST_1.attack("ST_2");
		ST_2.takeDamage(20);
		ST_1.attack("ST_2");
		ST_2.takeDamage(20);
		ST_2.attack("ST_1");
		ST_1.takeDamage(20);
		ST_2.guardGate();
		ST_2.beRepaired(10);
		ST_2.beRepaired(10);
		ST_2.beRepaired(10);
		ST_2.beRepaired(10);

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;
	
	return (0);
}