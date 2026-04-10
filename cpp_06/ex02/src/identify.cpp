/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:25:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/04/10 10:17:37 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Base.hpp"
#include	"../inc/A.hpp"
#include	"../inc/B.hpp"
#include	"../inc/C.hpp"
#include	"iostream"
#include	<cstdlib>

/*
	catch (...) = catch any exception of any type
	in this case our catch get the exception but it's empty
	therefore it moves to the next try.
	we know that either way we will get A, B or C
*/

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\t" << "address: " << p << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B\t" << "address: " << p << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C\t" << "address: " << p <<std::endl;
	else
		std::cout << "unknown" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\t" << "address: " << &p << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\t" << "address: " << &p << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\t" << "address: " << &p << std::endl;
		return ;
	}
	catch (...) {}
}
