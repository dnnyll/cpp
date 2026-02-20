/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:22:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/20 10:34:24 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef		FRAGTRAP_HPP
# define	FRAGTRAP_HPP

#include <string>
#include "../inc/ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
	
	//	OCF
	FragTrap(const std::string &inputName);
	FragTrap(const FragTrap &copy);
	FragTrap	&operator=(const FragTrap &source);	//	<--	copy assignment operator
	~FragTrap();									//	<--	destructor
	
	//	member functions
	void	highFivesGuys(void);
	void	attack(const std::string& target);
};

#endif