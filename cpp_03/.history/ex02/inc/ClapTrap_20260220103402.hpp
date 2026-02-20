/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:00:33 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/20 10:34:02 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CLAPTRAP_HPP
# define	CLAPTRAP_HPP

#include <string>

class	ClapTrap
{
	protected:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

	public:

	//	this is the orthodox canonical form - OCF
	ClapTrap(const std::string &inputName);			//	<--	default constructor
	ClapTrap(const ClapTrap &copy);					//	<--	copy constructor
	ClapTrap	&operator=(const ClapTrap &source);	//	<-- copy assignment operator
	~ClapTrap();

	//	member functions
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif

/*
	+---------------------------------------------------------------+
	|                    C++ ACCESS SPECIFIERS                      |
	+------------+--------------+----------------+------------------+
	| Specifier  | Same Class   | Derived Class  | Outside Code     |
	+------------+--------------+----------------+------------------+
	| public     |     YES      |      YES       |       YES        |
	| protected  |     YES      |      YES       |       NO         |
	| private    |     YES      |      NO        |       NO         |
	+------------+--------------+----------------+------------------+

*/