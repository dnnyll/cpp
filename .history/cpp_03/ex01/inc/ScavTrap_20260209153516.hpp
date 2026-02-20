/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:09:11 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 15:35:16 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP

#include <string>

class	ScavTrap : 
{
	private:
		
		void	guardGate();
		
	public:
	
	//	this is the orthodox canonical form - OCF
	ScavTrap(const std::string &inputName);			//	<--	default constructor
	ScavTrap(const ScavTrap &copy);					//	<--	copy constructor
	ScavTrap	&operator=(const ScavTrap &source);	//	copy assignment operator
	~ScavTrap();									//	<--	destructor
	
};

#endif