/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:34:10 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/09 16:19:23 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void	contact::set_first_name(std::string first)
{
	first_name = first;
}

void	contact::set_last_name(std::string last)
{
	last_name = last;
}

void	contact::set_nickname(std::string nick)
{
	nickname = nick;
}

void	contact::set_phone_number(std::string number)
{
	phone_number = number;
}

void	contact::set_darkest_secret(std::string secret)
{
	darkest_secret = secret;
}

std::string	contact::get_first_name() const
{
	return (first_name);
}

std::string	contact::get_last_name() const
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