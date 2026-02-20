/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:22:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 13:24:00 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef		FRAGTRAP_HPP
# define	FRAGTRAP_HPP

#include <string>
#include "../inc/ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
	
	//	this is the orthodox canonical form - OCF
	FragTrap(const std::string &inputName);			//	<--	default constructor
	FragTrap(const FragTrap &copy);					//	<--	copy constructor
	FragTrap	&operator=(const FragTrap &source);	//	<--	copy assignment operator
	~FragTrap();									//	<--	destructor
	
	//	member functions
	void	guardGate();
	void	attack(const std::string& target);
};

#endif