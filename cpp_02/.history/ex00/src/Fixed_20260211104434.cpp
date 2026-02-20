/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:52:34 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/11 10:44:34 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

//	default constructor
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//	copy constructor
Fixed::Fixed(const Fixed &source): _rawBits(source._rawBits)
{
	std::cout << "Copy constructor called\n";
}

/*	
operator= is both the function name and the mechanism that defines
how the equal sign behaves the class: Fixed.
when we call c = b in the main, this kicks in.
*/

//	copy assignment operator
Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
		this->_rawBits = source.getRawBits();
	return (*this);
}

//	default constructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//	get function
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

//	set function
void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}
