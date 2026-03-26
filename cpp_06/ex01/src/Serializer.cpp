/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:47:53 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 09:26:23 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Serializer.hpp"
#include	<iostream>

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

//	takes a memory address(pointer) -> converts to a raw number
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
//	takes a raw number -> converts to a memory address(pointer)
Data*	Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}
