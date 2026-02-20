/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:43:05 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/11 11:54:58 by daniefe2         ###   ########.fr       */
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
Fixed::Fixed(const Fixed &source) : _rawBits(source._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

//	copy assignment operator
Fixed	&Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
		this->_rawBits = source.getRawBits();
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
int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

float	Fixed::toFloat(void) const
{
	return static_cast<float>(_rawBits) / (1 << _fractionalBits);	//converts Fixed → int
}

//	stream insertion operator
//	overloads the << operator for your the class Fixed
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();		//converts Fixed → float
	return (out);
}

//	comparison operators ex01
//	const ensures read-only behavior
//	needed for comparisons to work on const objects
bool	Fixed::operator>(const Fixed &source) const
{
	bool	result;

	result = this->_rawBits > source._rawBits;
	return (result);
}

bool	Fixed::operator<(const Fixed &source) const
{
	bool	result;

	result = this->_rawBits < source._rawBits;
	return (result);
}

bool	Fixed::operator>=(const Fixed &source) const
{
	bool	result;

	result = this->_rawBits >= source._rawBits;
	return (result);
}

bool	Fixed::operator<=(const Fixed &source) const
{
	bool	result;

	result = this->_rawBits <= source._rawBits;
	return (result);
}

bool	Fixed::operator==(const Fixed &source) const
{
	bool	result;

	result = this->_rawBits == source._rawBits;
	return (result);
}

bool	Fixed::operator!=(const Fixed &source) const
{
	bool	result;

	result = this->_rawBits != source._rawBits;
	return (result);
}

//	arithmetic operators ex01
//	const ensures read-only behavior
Fixed	Fixed::operator+(const Fixed &source) const
{
	Fixed	result;
	
	result.setRawBits(this->_rawBits + source._rawBits);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &source) const
{
	Fixed	result;
	
	result.setRawBits(this->_rawBits - source._rawBits);
	return (result);
}
// multiply two Fixed numbers
// 1. convert _rawBits to long long to avoid overflow
// 2. multiply the raw integers
// 3. Shift right by _fractionalBits to correct the scale
// 4. Store result in a new Fixed object
Fixed	Fixed::operator*(const Fixed &source) const
{
	Fixed		result;
	long long	numerator;
	
	numerator = static_cast<long long>(this->_rawBits) * source._rawBits;
	result.setRawBits(static_cast<int>(numerator >> _fractionalBits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed &source) const
{
	Fixed		result;
	long long	numerator;
	
	numerator = static_cast<long long>(this->_rawBits) << _fractionalBits;
	//	convert _rawBits to long long to avoid overflow and shift left by _fractionalBits (× 2^fractionalBits)
	//	this allows not to lose the fractional part.
	//	prepares for int division while keeping the fractional precision
	result.setRawBits(static_cast<int>(numerator / source._rawBits));
	//	divide, convert back to int and stores the result in _raw_bits
	return (result);
}

//	increment/decrement operators ex01
//	x++
//	increment happens after we get the value
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);	//	save old value

	++_rawBits;				//	increments
	return (temp);			//	returns initial value
}

//	++x
Fixed	&Fixed::operator++()
{
	++_rawBits;
	return (*this);
}

//	x--
//	decrement happens after we get the value
Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);	//	save old value

	--_rawBits;				//	decrements
	return (temp);			//	returns initial value
}

//	--x
Fixed	&Fixed::operator--()
{
	--_rawBits;
	return (*this);
}

//	All four functions pick min or max, the difference is just:
//	const → read-only
//	non-const → can modify

// Non-const min
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
	//	or: return (a > b ? a : b);
}

//	const min
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
	//	or: return (a > b ? a : b);
}

//	non-const max
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
	//	or: return (a > b ? a : b);
}

//	const max
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
	//	or: return (a > b ? a : b);
}

