/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:14:00 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/22 19:27:07 by daniefe2         ###   ########.fr       */
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

	// makes Animal abstract: cannot be instantiated
	virtual void		makeSound() const = 0;	// = NULL -> makes object abstract
	std::string			getType() const;
	
	// virtual methods for Brain support
	virtual void		setIdea(int index, const std::string& idea) = 0;
	virtual std::string	getIdea(int index) const = 0;
};

#endif
