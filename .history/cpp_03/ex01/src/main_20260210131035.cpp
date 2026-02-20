/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 13:10:35 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main(void)
{
	std::cout << "\nLaunching ClapTrap Tournament..." << std::endl;
	{
		std::cout << "Constructing constestents...\n" << std::endl;
		
		ClapTrap	CT("CT");
		ScavTrap	ST("ST");

		std::cout << "\nEngaging in combat...\n" << std::endl;

		CT.attack("ST");
		ST.takeDamage(0);
		CT.attack("ST");
		ST.takeDamage(0);
		CT.attack("ST");
		ST.takeDamage(3);
		ST.guardGate();
		
		
		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;
	
	return (0);
}