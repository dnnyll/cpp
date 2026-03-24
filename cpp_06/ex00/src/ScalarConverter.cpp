/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:23:42 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/24 15:53:19 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/ScalarConverter.hpp"
#include	"../inc/ParseInputType.hpp"
#include	"../inc/PrintConversion.hpp"
#include	<cmath>
#include	<string>
#include	<cstdlib>
#include	<stdexcept>
#include	<limits>

//	default constructor
ScalarConverter::ScalarConverter()
{
	std::cout << "[ScalarConverter]\tdefault constructor called" << std::endl;
}

//	copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "[ScalarConverter]\tcopy constructor called" << std::endl;
	(void)&copy;
}

//	copy assignment operator
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &source)
{
	std::cout << "[ScalarConverter]\tcopy assignment operator called" << std::endl;
	(void)&source;
	return (*this);
}

//	destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "[ScalarConverter]\tdestructor called" << std::endl;
}



double convertToDouble(const std::string& input, InputType type)
{
	switch (type)
	{
		case CHAR:
			return static_cast<double>(input[0]);

		case INT:
			return static_cast<double>(std::atoi(input.c_str()));

		case FLOAT:
			return static_cast<double>(std::atof(input.c_str()));

		case DOUBLE:
			return std::atof(input.c_str());

		case PSEUDO:
			if (input == "nan" || input == "nanf")
				return std::numeric_limits<double>::quiet_NaN();
			if (input == "+inf" || input == "+inff")
				return std::numeric_limits<double>::infinity();
			if (input == "-inf" || input == "-inff")
				return -std::numeric_limits<double>::infinity();

		default:
			throw std::invalid_argument("Invalid input");
	}
}

void	ScalarConverter::convert(const std::string& input)
{
	InputType	type = detectType(input);
	
	if (type == INVALID)
	{
		// invalidInput();
		return ;
	}
	
	double	inputValue = convertToDouble(input, type);
	printChar(inputValue);
	// printInt(inputValue);
	// printFloat(inputValue);
	// printDouble(inputValue);
}