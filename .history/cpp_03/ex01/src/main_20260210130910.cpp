/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:34:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 13:09:10 by daniefe2         ###   ########.fr       */
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
		
		ClapTrap	ct("CT");
		ScavTrap	st("ST");

		std::cout << "\nEngaging in combat...\n" << std::endl;

		

		st.guardGate();
		st.beRepaired(1);
		st.beRepaired(1);
		st.beRepaired(1);
		st.beRepaired(1);
		ct.beRepaired(1);
		ct.beRepaired(1);
		
		std::cout << "\nDestroying constestents...\n" << std::endl;
	}
	std::cout << "\n------======Battle concluded...======------\n" <<std::endl;
	
	return (0);
}