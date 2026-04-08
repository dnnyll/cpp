/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:32:15 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 13:43:59 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Base.hpp"
#include	"../inc/A.hpp"
#include	"../inc/B.hpp"
#include	"../inc/C.hpp"
#include	<iostream>
#include	<cstdlib>
#include	<ctime>


//	declaring global functions 
Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main()
{
	{
		srand(time(NULL));
		
		Base	*test1 = generate();
		identify(test1);
		identify(*test1);
		delete test1;

		Base	*test2 = generate();
		identify(test2);
		identify(*test2);
		delete test2;

		Base	*test3 = generate();
		identify(test3);
		identify(*test3);
		delete test3;
	}
	return (0);
}
