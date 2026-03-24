/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:23:42 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/24 12:48:40 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/ScalarConverter.hpp"
#include	"../inc/ParseInputType.hpp"

//	default constructor
ScalarConverter::ScalarConverter()
{
	std::cout << "[ScalarConverter]\tdefault constructor called" << std::endl;
}

//	copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "[ScalarConverter]\tcopy constructor called" << std::endl;
	(void)copy;
}

//	copy assignment operator
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &source)
{
	std::cout << "[ScalarConverter]\tcopy assignment operator called" << std::endl;
	(void)copy;
	return (*this);
}

//	destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "[ScalarConverter]\tdestructor called" << std::endl;
}

static void	convert(std::string& input)
{
	InputType	type = detectType(input);
	
	if (type == INVALID)
	{
		invalidInput();
		return ;
	}
	
	double	inputValue = convertToDouble(input, type);
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}