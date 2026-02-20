/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:42:41 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/10 15:50:55 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/Fixed.hpp"

int	main( void )
{
	//	create 3 objects
	Fixed	a;		// Default constructor called → a._rawBits = 0
	Fixed	b(a);		// Copy constructor called    → b._rawBits = a._rawBits
	Fixed	c;		// Default constructor called → c._rawBits = 0

	c = b;			// Copy assignment operator called → this = c, other = b, copies _rawBits

	/*	when the code hits this equal sign, it will look and call the
	//	function: Fixed &Fixed::operator=(const Fixed &other)
	//	within this function, the keyword "this" will get the value
	//	stored in c and other will get the value stored in b
	//	it will then check if this != &other to avoid self-assignment
	//	and copy the internal _rawBits from other into this
	//	finally it will return *this so that chained assignments would work */
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return (0);
}

/*
	Start of main:

	a created → Default constructor
	b created → Copy constructor (calls copy assignment inside)
	c created → Default constructor

	c = b      → Copy assignment operator

	End of main:
	c destroyed → Destructor
	b destroyed → Destructor
	a destroyed → Destructor

*/