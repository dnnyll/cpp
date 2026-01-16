/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:09:15 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 10:44:24 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

/*
	Stack objects have automatic lifetime
	No delete
	Safe, fast, simple
	Scope-bound
	randomChump shows the correct way to create short-lived objects in C++
*/

//	stack allocation
void	randomChump(std::string name)
{
	Zombie	z(name);	//	constructor runs here
	z.announce();		//	calls the zombie
}	//	destruction is automatically called here