/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:03:30 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 11:03:55 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP
# define	DOG_HPP

#include <string>
#include "../inc/Animal.hpp"

class	Dog : public Animal
{
	public:
	
	//OCF
	();
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &source);
	~Cat();

	void	makeSound() const;
};

#endif