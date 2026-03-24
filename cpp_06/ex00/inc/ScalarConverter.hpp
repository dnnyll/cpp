/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 10:57:02 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/24 12:49:00 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCALARCONVERTER_HPP
# define	SCALARCONVERTER_HPP

#include	<iostream>
#include	<string>


class	ScalarConverter
{
	private:
	
	//OCF
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter	&operator=(const ScalarConverter &source);
	~ScalarConverter();

	public:
	
	static void	convert(std::string input);
};

#endif