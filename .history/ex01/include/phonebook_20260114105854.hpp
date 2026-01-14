/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:39:28 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/14 10:58:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		index;
		int		count;
		
		std::string truncate(const std::string& str);
	public:
		PhoneBook();
		void add_contact();
		void search() const;
};

#endif