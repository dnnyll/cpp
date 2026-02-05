/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:33:44 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/05 14:33:50 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect number of arguments.\n";
		std::cerr << "Usage: ./sed <filename> <s1> <s2>\n";
		return (1);
	}
	Sed	sed(argv[1], argv[2], argv[3]);
	sed.run();
	return (0);
}
