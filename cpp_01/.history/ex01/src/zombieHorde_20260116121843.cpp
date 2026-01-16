/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:09:29 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 12:18:43 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	int		i;
	Zombie	*zombie_array;
	zombie_array = new Zombie[N];
	i = 0;
	while (i < n)
	{
		zombie_array[i].set_name(name);
		i++;
	}
	return (zombie_array);
}