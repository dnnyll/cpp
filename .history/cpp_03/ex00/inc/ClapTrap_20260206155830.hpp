/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:48:49 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/06 15:58:30 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CLAPTRAP_HPP
# define	CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	private:

	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attackDamage;

	public:

	//	this is the orthodox canonical form - OCF
	Fixed();								//	<--	default constructor
	Fixed(const Fixed &other);				//	<--	copy constructor
	Fixed &operator=(const Fixed &other);	//	<--	copy assignment
	~Fixed();								//	<--	destructor

	//	accessors: functions that let you safely read or change a value inside an object
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif