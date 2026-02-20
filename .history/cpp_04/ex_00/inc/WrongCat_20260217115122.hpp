
#ifndef		WrongCat_HPP
# define	WrongCat_HPP

#include <string>
#include "../inc/Animal.hpp"

class	WrongCat : public Animal
{
	public:
	
	//OCF
	WrongCat();
	WrongCat(const WrongCat &copy);
	WrongCat	&operator=(const WrongCat &source);
	virtual	~WrongCat();

	void	makeSound() const;
};

#endif