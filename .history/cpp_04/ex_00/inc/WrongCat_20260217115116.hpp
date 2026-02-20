
#ifndef		CAT_HPP
# define	CAT_HPP

#include <string>
#include "../inc/Animal.hpp"

class	Cat : public Animal
{
	public:
	
	//OCF
	Cat();
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &source);
	virtual	~Cat();

	void	makeSound() const;
};

#endif