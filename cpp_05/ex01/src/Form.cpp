/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 09:14:29 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/18 13:46:03 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>

//	constructor
Form::Form(const std::string& name, int authzSign, int authzExec)
	: _name(name),
	_signature(false),
	_authzSign(authzSign),
	_authzExec(authzExec)
{
	std::cout << "[Form]\t constructor called" << std::endl;

	if (authzSign < 1 || authzExec < 1)
		throw GradeTooHighException();
	if (authzSign > 150 || authzExec > 150)
		throw GradeTooLowException();
}

//	copy constructor
Form::Form(const Form &copy)
	: _name(copy._name),
	_signature(false),
	_authzSign(copy._authzSign),
	_authzExec(copy._authzExec)
{
	std::cout << "[Form]\tcopy constructor called" << std::endl;
}


//	copy assignment operator
Form&	Form::operator=(const Form &source)
{
	std::cout << "[Form]\tcopy assignment operator called" << std::endl;

	if (this != &source)
		this->_signature = source._signature;
	return *this;
}

//	destructor
Form::~Form()
{
	std::cout << "[Form]\tdestructor called" << std::endl;
}

//	accessors
const	std::string& Form::getName() const
{
	return (this->_name);
}

bool	Form::getSignature() const
{
	return (this->_signature);
}

int		Form::getAuthzSign() const
{
	return(this->_authzSign);
}

int		Form::getAuthzExec() const
{
	return (this->_authzExec);
}

//	actions
void	Form::beSigned(const Bureaucrat& input)
{
	if (input.getGrade() > _authzSign)
		throw GradeTooLowException();
	_signature = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

//	operator overload
std::ostream& operator<<(std::ostream& out, const Form& input)
{
	out << input.getName()
	<< ", signed: " << (input.getSignature() ? "true" : "false")
	<< ", grade required to sign: " << input.getAuthzSign()
	<< ", grade required to execute: " << input.getAuthzExec();
	return (out);
}
