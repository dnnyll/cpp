/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:43:05 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/11 12:49:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

//	default constructor
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//	int constructor
Fixed::Fixed(int n)
{
	_rawBits = n << _fractionalBits;
	std::cout << "Int constructer called" << std::endl;
}

//	float constructor

Fixed::Fixed(float n)
{
	_rawBits = roundf(n * (1 << _fractionalBits));
	std::cout << "Float constructor called" << std::endl;
}

//	copy constructor
Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

//	copy assignment operator
Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other.getRawBits();
	return (*this);
}

//	destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//	accessors
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

//	converters
//	to int
//	960 >> 8 = 960 / 256 = 3
int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

//	convert to float
//	_rawBits = 3.75 * 256 = 960
960 / 256 = 3.75

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

//	stream insertion operator
//overloads operator<< = tells C++ how to print your class objects
std::ostream	&operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();	//	convert Fixed → float, then print
	return (out);
}
