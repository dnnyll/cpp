/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:41:35 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 16:02:57 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP
# define	FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	//	orthodox Canonical Form (OCF)
	Fixed();								//	default constructor
	Fixed(const Fixed &other);				//	copy constructor
	Fixed &operator=(const Fixed &other);	//	copy assignment operator
	~Fixed();								//	destructor
	Fixed(int n);							//	int constructor
	Fixed(float n);							//	float constructor

	//	accessors
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	//	converters
	int		toInt(void) const;
	float	toFloat(void) const;
};

// Stream insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
