/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:32:15 by daniefe2          #+#    #+#             */
/*   Updated: 2026/04/10 10:22:23 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Base.hpp"
#include	"../inc/A.hpp"
#include	"../inc/B.hpp"
#include	"../inc/C.hpp"
#include	<iostream>
#include	<cstdlib>
#include	<ctime>

//	declaring global functions (not contained withing hpp files)
Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main()
{
	{
		srand(time(NULL));
		
		Base	*test1 = generate();
		std::cout << test1 << std::endl;
		identify(test1);
		identify(*test1);

		Base	*test2 = generate();
		std::cout << test1 << std::endl;
		identify(test2);
		identify(*test2);

		Base	*test3 = generate();
		std::cout << test1 << std::endl;
		identify(test3);
		identify(*test3);

		delete test1;
		delete test2;
		delete test3;
	}
	return (0);
}
