#include "../inc/Bureaucrat.hpp"

//	default constructor
Bureaucrat::Bureaucrat(std::string input_name, int input_grade)
{
	std::cout << "[Bureaucrat]\t default constructor call" << std::endl;
	name = input_name;
	grade = input_grade;
}

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << "[Bureaucrat]\tcopy constructor called" << std::endl;
	*this = copy;
}

// copy assignment operator
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &source)
{
	std::cout << "[Bureaucrat]\tcopy assignment operator called" << std::endl;
	if (this != &source)
		type = source.type;
	return (*this);
}

// destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat]\tdestructor called" << std::endl;
}