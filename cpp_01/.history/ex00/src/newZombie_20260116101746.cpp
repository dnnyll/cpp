/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:09:29 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 10:17:46 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include Zombie.hpp

/*
	Heap objects have manual lifetime
	Require new / delete
	Persist beyond scope
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