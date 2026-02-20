/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 12:38:21 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ClapTrap.hpp"

int	main(void)
{
	std::cout << "\nLaunching ClapTrap Tournament..." << std::endl;
	
	//	Regular combat
	{
		std::cout << "Constructing constestents...\n" << std::endl;
		
		ClapTrap	Original("OG");
		ClapTrap	Clone("Clone");
		
		std::cout << "\nRegular attack test\t\t======------\n" << std::endl;
		Original.attack("Clone");
		Clone.takeDamage(0);
		Clone.attack("OG");
		Original.takeDamage(0);

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;

	//	Combat with different takeDamage values
	{
		std::cout << "Constructing constestents...\n" << std::endl;

		ClapTrap	Original("OG");
		ClapTrap	Clone("Clone");

		std::cout << "\nDifferent takeDamage test\t======------\n" << std::endl;
		
		Original.attack("Clone");
		
		Clone.takeDamage(4);
		Clone.beRepaired(2);
		Clone.beRepaired(3);

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;

	//	Combat estroyed
	{
		std::cout << "Constructing constestents...\n" << std::endl;

		ClapTrap	Original("OG");
		ClapTrap	Clone("Clone");

		std::cout << "\nDestroyed test\t======------\n" << std::endl;

		Clone.attack("OG");
		Original.takeDamage(0);
		Clone.attack("OG");
		Original.takeDamage(0);
		Original.attack("Clone");
		Clone.takeDamage(20);
		Clone.beRepaired(10);
		Clone.attack("OG");

		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;

	return (0);
}