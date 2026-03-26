/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:47:53 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 08:02:39 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Serializer.hpp"
#include	<iostream>
#include	<cstdint>

//	default constructor
Serializer::Serializer()
{
	std::cout << "[Serializer]\tdefault constructor called" << std::endl;
}

//	copy constructor
Serializer::Serializer(const Serializer &copy)
{
	std::cout << "[Serializer]\tcopy constructor called" << std::endl;
	(void)&copy;
}

//	copy assignment operator
Serializer	&Serializer::operator=(const Serializer &source)
{
	std::cout << "[Serializer]\tcopy assignment operator called" << std::endl;
	(void)&source;
	return (*this);
}

//	destructor
Serializer::~Serializer()
{
	std::cout << "[Serializer]\tdestructor called" << std::endl;
}

Casting: Use reinterpret_cast for these conversions. It is the C++ standard way to cast between pointers and integers.
Example: reinterpret_cast<uintptr_t>(ptr)
Example: reinterpret_cast<Serializer*>(raw)

//	takes a memory address(pointer) -> converts to a raw number
static	uintptr_t serialize(Serializer* ptr)
{
	
}
//	takes a raw number -> converts to a memory address(pointer)

static	Serializer* deserialize(uintptr_t raw)
{
	
}