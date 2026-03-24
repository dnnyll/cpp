/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintConversion.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:50:52 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/24 15:56:07 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/PrintConversion.hpp"
#include	<iostream>
#include	<cmath>
// #include	<string>
// #include	<cstdlib>
// #include	<stdexcept>
// #include	<limits>

void	printChar(double input)
{
	std::cout << "char: ";
	
	if (std::isnan(input) || input < 0 || input > 127)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	char	c = static_cast<char>(input);
	if(!std::isprint(c))
	{
		std::cout << "non displayable" << std::endl;
		return ;
	}
	std::cout << c << std::endl; 
}

void	printInt(double input)
{
	std::cout << "int: ";
	
}

// void	printFloat(double input)
// {
	
// }

// void	printDouble(double input)
// {
	
// }