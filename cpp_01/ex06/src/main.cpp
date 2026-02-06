/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 17:06:45 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/06 12:00:08 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HarlFilter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Allowed levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
		std::cerr << "Usage: ./harl <LEVEL>" << std::endl;
		return (1);
	}

	Harl	harl;
	harl.complainFiltered(argv[1]);

	return (0);
}
