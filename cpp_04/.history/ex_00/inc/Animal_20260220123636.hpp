/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:14:00 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/20 12:36:36 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

#include <iostream>
#include <string>

class	Animal
{
	protected:

	std::string	type;

	public:

	//OCF
	Animal();
	Animal(const Animal &copy);
	Animal	&operator=(const Animal &source);
	virtual	~Animal();

	virtual void	makeSound() const;	//	the compiler create a vtable at compile time
	std::string		getType() const;
};

#endif