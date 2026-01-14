/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:36:53 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/14 12:15:32 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

//	----------== constructors ==----------
//	creates a PhoneBook object 
//	initializes internal counters
PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
}

//	----------== add_contact ==----------
//	prompts the user to enter contact information
//	stores the input value
void PhoneBook::add_contact()
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

//	----------== truncate ==----------
//	truncates a string to 10 characters for display purposes
//	if the str > is longer than 10 characters
//	replaces last character with '.'
std::string PhoneBook::truncate(const std::string& str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

int	PhoneBook::search() const
{
	if (count == 0)
		return (1);

	int	i;

	i = 0;
	while (i < count)
	{
		std::cout	<< "|";
		std::cout	<< std::setw(10) << i + 1 << "| ";
		std::cout	<< std::setw(10) << truncate(contacts[i].get_first_name()) << "| ";
		std::cout	<< std::setw(10) << truncate(contacts[i].get_last_name()) << "| ";
		std::cout	<< std::setw(10) << truncate(contacts[i].get_nickname()) << "|\n";
		i++;
	}
	return (0);
}
