/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:02:30 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/27 15:40:21 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"
#include <iostream>

//	constructor
Harl::Harl(void) {}
//	destructor
Harl::~Harl(void) {}

void Harl::debug(void)
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

void Harl::complain(std::string level)
{
	int	i;

	i = 0;
	
	//	create an array with string/keywords
	std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	//	adds adresses of functions from object Harl to each of the array's index
	void (Harl::*funcs[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

/*	levels[ ]      funcs[ ] (pointers)
	+-------+      +-----------------+
	| "DEBUG"  | ↔ | &Harl::debug     |
	| "INFO"   | ↔ | &Harl::info      |
	| "WARNING"| ↔ | &Harl::warning   |
	| "ERROR"  | ↔ | &Harl::error     |
	+-------+      +-----------------+
*/
	
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*funcs[i])();
			return ;
		}
		i++;
	}
}

void Harl::complainFiltered(std::string level)
{
    int lvl;

    if (level == "DEBUG")      lvl = 0;
    else if (level == "INFO")  lvl = 1;
    else if (level == "WARNING") lvl = 2;
    else if (level == "ERROR") lvl = 3;
    else
    {
        std::cout << "[ Probably complaining about insignificant problems ]\n"
                  << "Although there are several ways to deal with Harl, one of the most effective is to SWITCH it off." 
                  << std::endl;
        return;
    }

    switch (lvl)
    {
        case 0:
            debug();
            info();
            warning();
            error();
            break;
        case 1:
            info();
            warning();
            error();
            break;
        case 2:
            warning();
            error();
            break;
        case 3:
            error();
            break;
    }
}
