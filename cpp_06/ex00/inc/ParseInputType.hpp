/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParseInputType.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:44:24 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/25 11:32:26 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PARSEINPUTTYPE_HPP
# define	PARSEINPUTTYPE_HPP

#include	"../inc/ScalarConverter.hpp"
#include	<string>

enum	InputType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,	// handles not numbers, infinity, etc
	INVALID
};

bool		isChar(const std::string& input);
bool		isInt(const std::string& input);
bool		isFloat(const std::string& input);
bool		isDouble(const std::string& input);
bool		isPseudoLiteral(const std::string& input);
InputType	detectType(const std::string& input);

#endif
