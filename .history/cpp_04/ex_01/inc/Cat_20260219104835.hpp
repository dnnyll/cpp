/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:30:32 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 10:48:35 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP
# define	CAT_HPP

#include <string>
#include "../inc/Animal.hpp"
#include "../inc/Brain.hpp"

class	Cat : public Animal
{
	private:

	Brain	*brain;

	public:
	
	//OCF
	Cat();
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &source);
	virtual	~Cat();

	void	makeSound() const;
	void	setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif