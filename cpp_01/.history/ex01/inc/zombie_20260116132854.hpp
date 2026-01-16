/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:56:23 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 13:28:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <cctype>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		
		void	announce(void);

	private:
		std::string	name;
};

Zombie*			newZombie(std::string name );
void			randomChump(std::string name);
Zombie	*zombieHorde(int N, std::string name)



#endif