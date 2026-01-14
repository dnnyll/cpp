/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:47:07 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/14 11:10:27 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.hpp>

void	print_intro(void)
{
	std::cout
		<< "\n"
		<< "--===||| My Awesome PhoneBook |||===--\n\n"
		<< "You may use the following commands:\n\n"
		<< "ADD :		to save a new contact\n"
		<< "SEARCH :	to display a specific contact\n"
		<< "EXIT :		to exit the program\n\n";
}

int	main(int argc, char **argv)	
{
	PhoneBook phonebook;
	(void)argv;
	if (argc != 1)
	{
		std::cerr << "Error: Please run the program without any arguments" << std::endl;
		return (1);
	}
	print_intro();
	std::string	input;
	while (1)
	{
		std::cout << "Enter a command: " << std::flush;;
		std::getline(std::cin, input);
		if (input == "ADD") 
		{
			std::cout << "ADD command executed." << std::endl;
			phonebook.add_contact();
		}
		else if (input == "SEARCH")
		{
			std::cout << "SEARCH command executed." << std::endl;
			if(phonebook.search() == 1)
				std::cerr << "Error: Phone book is currently empty." << std::endl;
		}
		else if (input == "EXIT") 
		{
			std::cout << "Whipping memory..." << std::endl;
			std::cout << "Exiting program..." << std::endl;
			break ;
		}
		else
			std::cerr << "Error: Unknown command. Please use a valid command" << std::endl;
	}
	return (0);
}