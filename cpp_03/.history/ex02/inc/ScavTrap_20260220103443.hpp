/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:09:11 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/20 10:34:43 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP

#include <string>
#include "../inc/ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
	
	//	OCF
	ScavTrap(const std::string &inputName);
	ScavTrap(const ScavTrap &copy);
	ScavTrap	&operator=(const ScavTrap &source);
	~ScavTrap();
	
	//	member functions
	void	guardGate();
	void	attack(const std::string& target);
};

#endif