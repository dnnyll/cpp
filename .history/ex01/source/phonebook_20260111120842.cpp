/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:36:53 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/11 12:08:42 by daniefe2         ###   ########.fr       */
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
	std::string input;
	
	std::cout << "First name: ";
	std::getline(cin, input);
	contacts[index].set_first_name(input);
	
	std::cout << "Last name: ";
	std::getline(cin, input);
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

    // 1. Ask user for each field
    // 2. Use setters on contacts[index]
    // 3. Increment index (wrap at 8)
    // 4. Update count (max 8)
}

void Phonebook::search() const
{
    // 1. Display table of all contacts
    // 2. Ask user to pick an index
    // 3. Display full info from contacts[index]
}
