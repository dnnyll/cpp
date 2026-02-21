/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:14:00 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/21 17:32:07 by daniefe2         ###   ########.fr       */
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

/*
		Memory layout:

	Animal* a = new Dog();
	+-------------------------+
	|      Dog object         |
	|-------------------------|
	| Animal part             |
	|  vtable pointer --------+--> [vtable]
	|  type = "Dog"           |
	|-------------------------|
	| Dog part                |
	|  Brain* brain ----------+--> [Brain object]
	+-------------------------+

	Virtual call flow:

	a->setIdea(0, "Bone");
	│
	▼ (a is Animal*, vtable lookup)
	[Dog::setIdea] runs
	│
	▼
	brain->setIdea(0, "Bone")
*/