/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:09:15 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 09:26:20 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ?

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
	z:.announce();
}	//	destruction is called here