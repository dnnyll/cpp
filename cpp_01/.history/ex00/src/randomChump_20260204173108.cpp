/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:09:15 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/04 17:31:09 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/zombie.hpp"

/*
	randomChump shows the correct way to create short-lived objects in C++
	stack objects have automatic lifetime
	doesn't use new/delete
	safe, fast, simple and scope-bound
*/

//	stack allocation
void	randomChump(std::string name)
{
	Zombie	z(name);	//	constructor runs here
	z.announce();		//	calls the zombie
}						//	destructor runs here