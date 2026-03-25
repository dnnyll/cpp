/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseInputType.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:44:10 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/25 12:10:41 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/ScalarConverter.hpp"
#include	"../inc/ParseInputType.hpp"
#include	<string>
#include	<cctype>
#include	<limits>
#include	<cstdlib>

bool	isChar(const std::string& input)
{
	if (input.length() != 1)
		return (false);

	if (std::isdigit(input[0]))
		return (false);

	if (input[0] < 32 || input[0] > 126)
		return (false);

	return (true);
}

bool	isInt(const std::string& input)
{
	size_t	i = 0;
	if (input[0] == '+' || input[0] == '-')
		i++;
		
	if (i > input.length())
		return (false);
	
	while (i < input.length())
	{
		if (!std::isdigit(input[i]))
			return (false);
		i++;
	}
	//	quick conversion for limits of int
	//	avoids convert error, of limit int is no longer considered an int
	double	inputValue = atof(input.c_str());

		if (inputValue > std::numeric_limits<int>::max() ||
			inputValue < std::numeric_limits<int>::min())
			return (false);
	return (true);
}

bool	isFloat(const std::string& input)
{
	size_t		i = 0;
	bool dotFound = false;

	if (input.empty())
		return (false);

	if (input[input.size() - 1] != 'f')
		return (false);

	std::string number = input.substr(0, input.size() - 1);

	if (number.empty())
		return (false);

	if (number[0] == '+' || number[0] == '-')
		i++;

	while (i < number.size())
	{
		if (number[i] == '.')
		{
			if (dotFound)
				return (false);
			dotFound = true;
		}
		else if (!std::isdigit(number[i]))
			return (false);
		i++;
	}
	return (dotFound);
}

bool	isDouble(const std::string& input)
{
	size_t	i = 0;
	bool	dotFound = false;

	if (input.empty())
		return (false);

	if (input[input.size() - 1] == 'f')
		return (false);

	if (input[0] == '+' || input[0] == '-')
		i++;

	while (i < input.size())
	{
		if (input[i] == '.')
		{
			if (dotFound)
				return (false);
			dotFound = true;
		}
		else if (!std::isdigit(input[i]))
			return (false);
		i++;
	}
	return (dotFound);
}

bool	isPseudoLiteral(const std::string& input)
{
	return	(input == "nan" ||
			input == "nanf" ||
			input == "+inf" ||
			input == "+inff" ||
			input == "-inf" ||
			input == "-inff");
}

InputType	detectType(const std::string& input)
{
	if (input.empty())
		return (INVALID);
	
	if (isChar(input))
		return (CHAR);

	if (isPseudoLiteral(input))
	{
		if (input[input.length() - 1] == 'f')
			return (FLOAT);
		else
			return (DOUBLE); 
	}

	if (isFloat(input))
		return (FLOAT);

	if (isDouble(input))
		return (DOUBLE);

	if (isInt(input))
		return (INT);

	else
		return (INVALID);
}
