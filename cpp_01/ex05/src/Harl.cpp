/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:02:30 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/06 12:17:59 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

//	constructor
Harl::Harl(void) {}
//	destructor
Harl::~Harl(void) {}

void	Harl::debug(void)
{
	std::cout
		<< "[ DEBUG ]\n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
		<< std::endl;
}

void Harl::info(void)
{
	std::cout
		<< "[ INFO ]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< std::endl;
}

void Harl::warning(void)
{
	std::cout
		<< "[ WARNING ]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< std::endl;
}

void Harl::error(void)
{
	std::cout
		<< "[ ERROR ]\n"
		<< "This is unacceptable! I want to speak to the manager now.\n"
		<< std::endl;
}

void	Harl::complain(std::string level)
{
	int	i;

	i = 0;
	
	//	creates array for comparison
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	//	creates array with pointers to member functions
	void (Harl::*funcs[4])(void) = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	//	search mechanism
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();	//	calls corresponding function stored in funcs[i]
			return ;
		}
		i++;
	}
}
