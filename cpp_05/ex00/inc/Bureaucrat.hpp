
#ifndef		Bureaucrat_HPP
# define	Bureaucrat_HPP

#include <iostream>
#include <string>

class	Bureaucrat
{
	protected:

	std::string	const name;
	int			grade;

	public:

	//OCF
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat	&operator=(const Bureaucrat &source);
	virtual	~Bureaucrat();

};

#endif