
#ifndef		WrongCat_HPP
# define	WrongCat_HPP

#include <string>
#include "../inc/WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
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