/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:05:29 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/04 17:34:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

//	Constructor
Weapon::Weapon(const std::string& type) : type(type) {}

//	Getter
const	std::string& Weapon::get_type() const
{
	return (type);
}

//	Setter
void	Weapon::set_type(const std::string& new_type)
{
	type = new_type;
}