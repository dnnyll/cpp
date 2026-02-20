/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:36:58 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 10:37:00 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Brain.hpp"

// default constructor
Brain::Brain()
{
	std::cout << "[Brain]\tdefault constructor called" << std::endl;
}

// copy constructor
Brain::Brain(const Brain &copy)
{
	std::cout << "[Brain]\tcopy constructor called" << std::endl;
	*this = copy;
}

// assignment operator
Brain	&Brain::operator=(const Brain &source)
{
	int	i;

	std::cout << "[Brain]\tassignment operator called" << std::endl;
	if (this != &source)
	{
		i = 0;
		while (i < 100)
		{
			ideas[i] = source.ideas[i];
			i++;
		}
		return (*this);
	}
}

// destructor
Brain::~Brain()
{
	std::cout << "[Brain]\tdestructor called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (indea[]);
}
