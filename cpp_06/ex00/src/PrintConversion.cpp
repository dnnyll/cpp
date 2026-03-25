/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintConversion.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:50:52 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/25 13:50:12 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/PrintConversion.hpp"
#include	<iostream>
#include	<cmath>
#include	<limits>
#include	<iostream>

void	printInvalidInput()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

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
	std::cout << ('\'') << c << ('\'') << std::endl; 
}

void	printInt(double input)
{
	std::cout << "int: ";
	if (std::isnan(input) ||
		input > std::numeric_limits<int>::max() ||
		input < std::numeric_limits<int>::min())
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(input) << std::endl;
}

void	printFloat(double input)
{
	std::cout << "float: ";

	if (std::isnan(input))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (input == std::numeric_limits<double>::infinity())
	{
		std::cout << "+inff" << std::endl;
		return ;
	}
	if ((input) == -std::numeric_limits<double>::infinity())
	{
		std::cout << "-inff" << std::endl;
		return ;
	}

	float	f = static_cast<float>(input);
	
	std::cout << f;

	if (input == static_cast<long>(input))
		std::cout << ".0";

	std::cout << "f" << std::endl;
}

void	printDouble(double input)
{
	std::cout << "double: ";

	if (std::isnan(input))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (input == std::numeric_limits<double>::infinity())
	{
		std::cout << "+inf" << std::endl;
		return ;
	}
	if ((input) == -std::numeric_limits<double>::infinity())
	{
		std::cout << "-inf" << std::endl;
		return ;
	}
	
	std::cout << input;

	if (input == static_cast<long>(input))
		std::cout << ".0" << std::endl;

}
