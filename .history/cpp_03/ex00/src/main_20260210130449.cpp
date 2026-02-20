/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 13:04:49 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ClapTrap.hpp"

int	main(void)
{
		ClapTrap	Original("OG");
		ClapTrap	CP("CP");
	

	std::cout << "\nLaunching ClapTrap Tournament..." << std::endl;
	
	//	Regular combat
	{
		std::cout << "Constructing constestents...\n" << std::endl;
		
		ClapTrap	Original("OG");
		ClapTrap	CP("CP");
		
		std::cout << "\nRegular attack test\t\t======------\n" << std::endl;
		Original.attack("CP");
		CP.takeDamage(0);
		CP.attack("OG");
		Original.takeDamage(0);

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;

	//	Combat with different takeDamage values + repair max hitpoints
	{
		std::cout << "Constructing constestents...\n" << std::endl;

		ClapTrap	Original("OG");
		ClapTrap	CP("CP");

		std::cout << "\nDifferent takeDamage test\t======------\n" << std::endl;
		
		Original.attack("CP");
		CP.takeDamage(4);
		CP.beRepaired(2);
		CP.beRepaired(3);

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;

	//	Combat estroyed
	{
		std::cout << "Constructing constestents...\n" << std::endl;

		ClapTrap	Original("OG");
		ClapTrap	CP("CP");

		std::cout << "\nDestroyed test\t======------\n" << std::endl;

		CP.attack("OG");
		Original.takeDamage(0);
		CP.attack("OG");
		Original.takeDamage(0);
		Original.attack("CP");
		CP.takeDamage(20);
		CP.beRepaired(10);
		CP.attack("OG");

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;

	return (0);
}