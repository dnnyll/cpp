/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:56:23 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 11:58:50 by daniefe2         ###   ########.fr       */
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
		void	set_name(const std::string &input_name);
		
	private:
		std::string	name;
};

Zombie	*	zombieHorde(int n, std::string name);

#endif