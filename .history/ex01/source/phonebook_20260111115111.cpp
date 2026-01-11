/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:36:53 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/11 11:51:11 by daniefe2         ###   ########.fr       */
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
    // 1. Ask user for each field
    // 2. Use setters on contacts[index]
    // 3. Increment index (wrap at 8)
    // 4. Update count (max 8)
}





std::string	Phonebook::search() const
{
	return ();
}

std::string	Phonebook::add_contact()
{
	return (first_name);
}