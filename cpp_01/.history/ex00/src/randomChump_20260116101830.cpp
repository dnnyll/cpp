/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:09:15 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 10:18:30 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

/*
	Stack objects have automatic lifetime
	No delete
	Safe, fast, simple
	Scope-bound
*/

//	stack allocation
void	randomChump(std::string name)
{
	Zombie	z(name);	
	z.announce();
}	//	destruction is called here