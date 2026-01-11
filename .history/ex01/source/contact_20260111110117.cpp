/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:34:10 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/11 11:01:17 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	Contact::set_first_name(std::string first)
{
	first_name = first;
}

void	Contact::set_last_name(std::string last)
{
	last_name = last;
}

void	Contact::set_nickname(std::string nick)
{
	nickname = nick;
}

void	Contact::set_phone_number(std::string number)
{
	phone_number = number;
}

void	Contact::set_darkest_secret(std::string secret)
{
	darkest_secret = secret;
}

std::string	Contact::get_first_name() const
{
	return (first_name);
}

std::string	Contact::get_last_name() const
{
	return (last_name);
}

std::string	contact::get_nickname() const
{
	return(nickname);
}

std::string	contact::get_phone_number() const
{
	return(phone_number);
}
std::string	contact::get_darkest_secret() const
{
	return(darkest_secret);
}