/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:42:41 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/11 10:57:07 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int	main(void)
{
	// Create objects using different constructors
	Fixed a;		// Default constructor → a._rawBits = 0
	Fixed b(a);		// Copy constructor → b._rawBits = a._rawBits
	Fixed c;		// default constructor → c._rawBits = 0

	c = b;            // Copy assignment → copies b._rawBits into c._rawBits
					// Steps inside operator=:
					// 1. 'this' refers to c, 'source' refers to b
					// 2. Check for self-assignment (this != &source)
					// 3. Copy _rawBits from source to *this
					// 4. Return *this for chained assignments

	// Access internal state using getters
	std::cout << a.getRawBits() << std::endl; // prints a._rawBits
	std::cout << b.getRawBits() << std::endl; // prints b._rawBits
	std::cout << c.getRawBits() << std::endl; // prints c._rawBits

	return 0;
}
// End of main: destructors called for c, b, a in reverse order of creation


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