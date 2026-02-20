/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 17:04:11 by daniefe2         ###   ########.fr       */
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
	ct.takeDamage(11);
	st.attack("CT");
	st.takeDamage(4);
	ct.attack("")
	st.guardGate();

	std::cout << "\nBattle concluded..." <<std::endl;
	return (0);
}