/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 07:05:02 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/04 17:34:15 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HUMAN_A
# define	HUMAN_A

#include <../inc/string>
#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(const std::string &game, Weapon &weapon);
		~HumanA(void);
		void	attack(void) const;
};

#endif