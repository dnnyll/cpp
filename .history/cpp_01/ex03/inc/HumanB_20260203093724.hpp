/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 10:46:25 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/26 11:31:19 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HUMAN_B
# define	HUMAN_B

#include <string>
#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	name;
		Weapon *weapon;
	
	public:
		HumanB(const std::string &name);
		void	set_weapon(Weapon &weapon);
		void	attack(void) const;
};

#endif