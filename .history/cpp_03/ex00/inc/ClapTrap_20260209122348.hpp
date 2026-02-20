/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:00:33 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/09 12:23:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CLAPTRAP_HPP
# define	CLAPTRAP_HPP

#include <string>

class	ClapTrap
{
	private:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

	public:

	//	this is the orthodox canonical form - OCF
	ClapTrap();										//	<--	default constructor
	ClapTrap(const ClapTrap &copy);					//	<--	copy constructor
	ClapTrap	&operator=(const ClapTrap &source);	//	copy assignment operator
	~ClapTrap();									//	<--	destructor

	//	accessors: functions that let you safely read or change a value inside an object
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif