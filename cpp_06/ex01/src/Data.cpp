/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:51:36 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/25 14:52:06 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Data.hpp"
//	default constructor
Data::Data()
{
	std::cout << "[Data]\tdefault constructor called" << std::endl;
}

//	copy constructor
Data::Data(const Data &copy)
{
	std::cout << "[Data]\tcopy constructor called" << std::endl;
	(void)&copy;
}

//	copy assignment operator
Data	&Data::operator=(const Data &source)
{
	std::cout << "[Data]\tcopy assignment operator called" << std::endl;
	(void)&source;
	return (*this);
}

//	destructor
Data::~Data()
{
	std::cout << "[Data]\tdestructor called" << std::endl;
}