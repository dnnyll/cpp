/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:30:05 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/24 15:46:33 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ScalarConverter.hpp"
#include	<string>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "error: incorrect number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}