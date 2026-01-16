/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 13:18:50 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 13:24:10 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zombie_array;
	int	i;
	
	zombie_array = new Zombie[N];
	i = 0;
	while (i < N)
	{
		zombie_array[i].set_name(name);
		i++;
	}
	return (zombie_array);
}