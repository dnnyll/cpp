/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 11:15:02 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main(void)
{
	std::cout << "\nLaunching ClapTrap Tournament..." << std::endl;
	std::cout << "Constructing constestents...\n" << std::endl;

	ClapTrap	ct("CT");
	ScavTrap	st("ST");

	std::cout << "\nEngaging in combat...\n" << std::endl;
	
	ct.attack("ST");
	st.takeDamage(11);
	st.attack("CT");
	ct.takeDamage(20);
	ct.beRepaired
	ct.attack("ST");
	ct.takeDamage(20);
	st.attack("CT");
	ct.takeDamage(13);
	// st.guardGate();
	// st.beRepaired(1);
	// st.beRepaired(1);
	// st.beRepaired(1);
	// st.beRepaired(1);
	// ct.beRepaired(1);
	// ct.beRepaired(1);
	std::cout << "\nBattle concluded..." <<std::endl;
	return (0);
}