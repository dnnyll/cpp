/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:39:28 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/09 17:26:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	#ifndef PHONEBOOK_HPP
	# define PHONEBOOK_HPP

	#include <iostream>
	#include <cctype>
	#include <string>

	class phonebook
	{
	private:
		// contact	contacts[id];
		int		index;
		int		completed;
	public:
		PhoneBook();
		void addContact();
		void search() const;     // display/search contacts
};

	};

#endif