/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:09:29 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/04 17:30:59 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/zombie.hpp"

/*
	heap objects have manual lifetime
	require new / delete
	persist beyond scope
	possible memory leaks if misused
*/

//	heap allocation
Zombie*	newZombie(std::string name )
{
	return (new Zombie(name));
}

/*
	usage:

	Zombie* z = newZombie("Foo");
	z->announce();
	delete z;  // mandatory

*/