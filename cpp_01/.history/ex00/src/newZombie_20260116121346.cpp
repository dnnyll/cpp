/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:09:29 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 12:13:46 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zombie.hpp"

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