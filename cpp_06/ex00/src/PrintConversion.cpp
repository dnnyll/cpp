/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintConversion.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:50:52 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/25 07:58:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/PrintConversion.hpp"
#include	<iostream>
#include	<cmath>
// #include	<string>
// #include	<cstdlib>
// #include	<stdexcept>
#include	<limits>

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
	int	inputValue = static_cast<int>(input);

	std::cout << "int: ";
	
	if (inputValue < std::numeric_limits<int>::min() || inputValue > std::numeric_limits<int>::max())
	{
		std::cout << "out of bounds" << std::endl;
		return ;
	}
	if (!std::isprint(inputValue))
	{
		std::cout << "non displayable" << std::endl;
	}
	std::cout << input << std::endl;
		
}

// void	printFloat(double input)
// {
	
// }

// void	printDouble(double input)
// {
	
// }