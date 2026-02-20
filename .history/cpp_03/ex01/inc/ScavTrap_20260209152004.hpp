/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:09:11 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 15:20:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP

#include <string>

class	ScavTrap
{
	private:

		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
		
		void guardGate();
	public:
	
	//	this is the orthodox canonical form - OCF
	ClapTrap(const std::string &inputName);			//	<--	default constructor
	ClapTrap(const ClapTrap &copy);					//	<--	copy constructor
	ClapTrap	&operator=(const ClapTrap &source);	//	copy assignment operator
	~ClapTrap();
										//	<--	destructor
	
}


#endif