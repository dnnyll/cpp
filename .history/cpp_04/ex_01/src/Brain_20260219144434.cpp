/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:36:58 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 14:44:34 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Brain.hpp"

// default constructor
Brain::Brain()
{
	std::cout << "[Brain]\t\tdefault constructor called" << std::endl;
}

// copy constructor
Brain::Brain(const Brain &copy)
{
	int	i;

	i = 0;
	std::cout << "[Brain]\t\tcopy constructor called" << std::endl;
	while (i < 100)
	{
		
	}
	
	*this = copy;
}

// copy assignment operator
Brain	&Brain::operator=(const Brain &source)
{
	int	i;

	std::cout << "[Brain]\t\tcopy assignment operator called" << std::endl;
	if (this != &source)
	{
		i = 0;
		while (i < 100)
		{
			ideas[i] = source.ideas[i];
			i++;
		}
	}
	return (*this);
}

// destructor
Brain::~Brain()
{
	std::cout << "[Brain]\t\tdestructor called" << std::endl;
}

//	set
void	Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

//	get
std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (ideas[index]);
	return "";
}
