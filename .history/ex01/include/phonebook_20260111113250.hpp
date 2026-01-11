/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:39:28 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/11 11:32:50 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include <string>
#include "contact.hpp"

class Phonebook
{
	private:
		Contact	contacts[8];
		int		index;
		int		count;
		int		completed;
	public:
		phonebook();
		void add_contact();
		void search() const;
};

#endif