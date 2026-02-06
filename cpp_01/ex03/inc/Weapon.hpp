/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 07:01:41 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/06 13:19:23 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WEAPON_HPP
# define	WEAPON_HPP

#include <string>

class	Weapon
{
	private:
		std::string	type;

	public:
	//	constructor
		Weapon(const std::string &type);
	//	accessors
		const	std::string &getType(void) const;
		void	setType(const std::string &type);
};

#endif