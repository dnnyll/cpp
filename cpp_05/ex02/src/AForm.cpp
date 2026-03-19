/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:31:19 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 14:53:46 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>

//	constructor
AForm::AForm(const std::string& name, int authzSign, int authzExec)
	: _name(name),
	_signature(false),
	_authzSign(authzSign),
	_authzExec(authzExec)
{
	std::cout << "[AForm]\t constructor called" << std::endl;

	if (authzSign < 1 || authzExec < 1)
		throw GradeTooHighException();
	if (authzSign > 150 || authzExec > 150)
		throw GradeTooLowException();
}

//	copy constructor
AForm::AForm(const AForm &copy)
	: _name(copy._name),
	_signature(false),
	_authzSign(copy._authzSign),
	_authzExec(copy._authzExec)
{
	std::cout << "[AForm]\tcopy constructor called" << std::endl;
}


//	copy assignment operator
AForm&	AForm::operator=(const AForm &source)
{
	std::cout << "[AForm]\tcopy assignment operator called" << std::endl;

	if (this != &source)
		this->_signature = source._signature;
	return *this;
}

//	destructor
AForm::~AForm()
{
	std::cout << "[AForm]\tdestructor called" << std::endl;
}

//	accessors
const	std::string& AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSignature() const
{
	return (this->_signature);
}

int		AForm::getAuthzSign() const
{
	return(this->_authzSign);
}

int		AForm::getAuthzExec() const
{
	return (this->_authzExec);
}

//	actions
void	AForm::beSigned(const Bureaucrat& input)
{
	if (input.getGrade() > _authzSign)
		throw GradeTooLowException();
	_signature = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

//	operator overload
std::ostream& operator<<(std::ostream& out, const AForm& input)
{
	out << input.getName()
	<< ", signed: " << (input.getSignature() ? "true" : "false")
	<< ", grade required to sign: " << input.getAuthzSign()
	<< ", grade required to execute: " << input.getAuthzExec();
	return (out);
}
