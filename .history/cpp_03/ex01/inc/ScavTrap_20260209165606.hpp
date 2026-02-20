/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:09:11 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 16:56:06 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP

#include <string>
#include "../inc/ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
	
	//	this is the orthodox canonical form - OCF
	ScavTrap(const std::string &inputName);			//	<--	default constructor
	ScavTrap(const ScavTrap &copy);					//	<--	copy constructor
	ScavTrap	&operator=(const ScavTrap &source);	//	copy assignment operator
	~ScavTrap();									//	<--	destructor
	
	void	guardGate();
	void	attack(const std::string& target);
};

#endif