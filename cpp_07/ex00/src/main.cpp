/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:01:56 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 15:22:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/TemplateOperations.hpp"
#include	"iostream"

int	main()
{
	{
		std::cout<< "personal tests" << std::endl;

		int	a;
		int	b;

		a = 7;
		b = 4;
		
		std::cout << "a =\t\t" << a << std::endl;
		std::cout << "b =\t\t" << b << std::endl;
		::swap(a, b);
		std::cout << "a =\t\t" << a << std::endl;
		std::cout << "b =\t\t" << b << std::endl;
		::min(a, b);
		std::cout << "min(a, b) =\t" << ::min(a, b) << std::endl;
		::max(a, b);	
		std::cout << "max(a, b) =\t" << ::max(a, b) << std::endl;
		std::cout << std::endl;
		char	c;
		char	h;
		
		c = 'c';
		h = 'h';
		
		std::cout << "c =\t\t" << c << std::endl;
		std::cout << "h =\t\t" << h << std::endl;
		::swap(c, h);
		std::cout << "c =\t\t" << c << std::endl;
		std::cout << "h =\t\t" << h << std::endl;
		::min(c, h);
		std::cout << "min(c, h) =\t" << ::min(c, h) << std::endl;
		::max(a, b);	
		std::cout << "max(c, h) =\t" << ::max(c, h) << std::endl;
		std::cout<< "\n==========================================\n" << std::endl;
	}
	
	{
		std::cout<< "subject's tests" << std::endl;

		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	}
	return (0);
}