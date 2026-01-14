/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:36:53 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/14 10:51:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
	PhoneBook

	Owns multiple Contact.
	Decides where to store them.
	Reads input.
	Displays results.
*/

Phonebook::Phonebook()
{
	index = 0;
	count = 0;
}
	
void Phonebook::add_contact()
{
	std::string	input;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	contacts[index].set_first_name(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	contacts[index].set_last_name(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	contacts[index].set_nickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	contacts[index].set_phone_number(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	contacts[index].set_darkest_secret(input);

	index = (index + 1) % 8;
	if (count < 8)
		count++;
}

void Phonebook::search() const
{
	std::string	Phonebook::truncate(const std::string& str)const
	{
		if (str.length() > 10)
		{
			return (str.substr(0, 9))
		}
	}

	
	int	i;

	i = 0;

	while (i < count)
	{
		std::cout	<< std::setw(10) << i << "|";
		std::cout	<< std::setw(10) << truncate(contacts[i].get_first_name()) << '|';
		std::cout	<< std::setw(10) << truncate(contacts[i].get_last_name()) << '|';
		std::cout	<< std::setw(10) << truncate(contacts[i].get_nickname()) << std::endl;
	}

    // 1. Display table of all contacts
    // 2. Ask user to pick an index
    // 3. Display full info from contacts[index]
}
