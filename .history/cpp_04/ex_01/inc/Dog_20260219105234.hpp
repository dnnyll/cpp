/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:03:30 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 10:52:34 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP
# define	DOG_HPP

#include <string>
#include "../inc/Animal.hpp"
#include "../inc/"

class	Dog : public Animal
{
	public:
	
	//OCF
	Dog();
	Dog(const Dog &copy);
	Dog	&operator=(const Dog &source);
	virtual	~Dog();

	void	makeSound() const;
};

#endif