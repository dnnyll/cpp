/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:39:28 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/14 16:00:03 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include "contact.hpp"

class	PhoneBook
{
	private:
		Contact		contacts[8];
		int			index;
		int			count;
		
		std::string	truncate(std::string str) const;
		
	public:
		PhoneBook();
		void		add_contact();
		int			search() const;
};

#endif