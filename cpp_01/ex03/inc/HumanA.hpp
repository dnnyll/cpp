/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 07:05:02 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/06 14:59:23 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HUMAN_A
# define	HUMAN_A

#include <string>
#include "../inc/Weapon.hpp"

class	HumanA
{
	private:
		std::string	name;
		Weapon		&weapon;	//reference to Weapon object

	public:
	//	constructor
		HumanA(const std::string &game, Weapon &weapon);
	//	deconstructor
		~HumanA(void);

		void	attack(void) const;
};

#endif