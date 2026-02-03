/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixedd.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:41:35 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/03 16:23:03 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionalBits = 8;

public:
	// Orthodox Canonical Form (OCF)
	Fixed();								// Default constructor
	Fixed(const Fixed &other);				// Copy constructor
	Fixed &operator=(const Fixed &other);	// Copy assignment operator
	~Fixed();								// Destructor

	// Accessors
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Converters
	int		toInt(void) const;
	float	toFloat(void) const;
};

// Stream insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
