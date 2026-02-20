/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:14:00 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 15:40:52 by daniefe2         ###   ########.fr       */
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

	virtual void		makeSound() const = 0;	// = NULL
	
	std::string			getType() const;
	// optional virtual methods for Brain support
	virtual void		setIdea(int index, const std::string& idea)
	{
		(void)index;
		(void)idea;
	};
	virtual std::string	getIdea(int index) const
	{
		(void)index;
		return "";
	};
};

#endif