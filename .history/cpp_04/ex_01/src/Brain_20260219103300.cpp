
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
			ideas[i]
		}
	}
		type = source.type;
	return (*this);
}

// destructor
Brain::~Brain()
{
	std::cout << "[Brain]\tdestructor called" << std::endl;
}

// default sound
void	Brain::makeSound() const
{
	std::cout << "============\tsome generic Brain sound\t============" << std::endl;
}

std::string Brain::getType() const
{
	return (type);
}
