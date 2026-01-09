/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:36:53 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/09 13:20:15 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
void	print_intro(void)
{
	std::cout << "\n";
	std::cout << "--===||| My Awesome PhoneBook |||===--" << std::endl;
	std::cout << "\n";
	std::cout << "You may use the following commands:" << std::endl;
	std::cout << "\n";
	std::cout << "ADD :		to save a new contact" << std::endl;
	std::cout << "SEARCH : to display a specific contact" << std::endl;
	std::cout << "EXIT: to exit the program" << std::endl;
	std::cout << "\n";
}

int	main(int argc, char **argv)
{
	(void)argv;
	print_intro();

	if (argc != 1)
		return (1);
	
	return(0);
}