/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:17:06 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 10:35:40 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Base.hpp"
#include	<iostream>

//	destructor
Base::~Base()
{
	std::cout << "[Base]\tdestructor called" << std::endl;
}
