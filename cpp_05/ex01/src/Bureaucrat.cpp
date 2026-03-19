/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:14:29 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 12:55:14 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "../inc/Bureaucrat.hpp"
// #include "../inc/Form.hpp"

//	constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade)
	:_name(name)
{
	std::cout << "[Bureaucrat]\tconstructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

//	copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: _name(copy._name), _grade(copy._grade)
{
	std::cout << "[Bureaucrat]\tcopy constructor called" << std::endl;
}


//	copy assignment operator
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &source)
{
	std::cout << "[Bureaucrat]\tcopy assignment operator called" << std::endl;
	if (this != &source)
		_grade = source._grade;
	return (*this);
}

//	destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat]\tdestructor called" << std::endl;
}

//	accessors
const	std::string& Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

//	actions
void	Bureaucrat::incrementGrade()
{
	std::cout << "[Bureaucrat]\tincrementGrade called" << std::endl;
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "[Bureaucrat]\tdecrementGrade called" << std::endl;
	if (this->_grade >= 150)
		throw GradeTooHighException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form& input) const
{
	try
	{
		input.beSigned(*this);
		std::cout << getName() << " signed " << input.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << input.getName() 
		<< " because " << e.what() << std::endl;
	}
}

//	exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

//	operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
