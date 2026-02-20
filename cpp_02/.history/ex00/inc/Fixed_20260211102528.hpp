/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:48:49 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/11 10:25:28 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

#include <iostream>

class	Fixed
{
	private:

	int					_rawBits;
	static const int	_fractionalBits = 8;

	public:

	//	this is the orthodox canonical form - OCF
	Fixed();									//	<--	default constructor
	Fixed(const Fixed &source);					//	<--	copy constructor
	Fixed	&operator=(const Fixed &source);	//	<--	copy assignment
	~Fixed();									//	<--	destructor

	//	accessors: functions that let you safely read or change a value inside an object
	//	get
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif