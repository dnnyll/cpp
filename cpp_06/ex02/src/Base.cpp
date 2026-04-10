/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:17:06 by daniefe2          #+#    #+#             */
/*   Updated: 2026/04/10 10:10:16 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Base.hpp"
#include	<iostream>

//	default constructor
Base::Base()
{
	std::cout << "[Base]\tdefault constructor called" << std::endl;
}

//	destructor
Base::~Base()
{
	std::cout << "[Base]\tdestructor called" << std::endl;
}
