/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:03:30 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 10:53:10 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP
# define	DOG_HPP

#include <string>
#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

class	Dog : public Animal
{
	private:
	
	

	public:
	
	//OCF
	Dog();
	Dog(const Dog &copy);
	Dog	&operator=(const Dog &source);
	virtual	~Dog();

	void		makeSound() const;
	void		setIdea(int index, const std::string& idea);
	std::string	getIdea(int index) const;
};

#endif