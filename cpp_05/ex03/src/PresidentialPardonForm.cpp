/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:41:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/20 14:42:46 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <string>

//	constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardon", 25, 5), _target(target)
{
	std::cout << "[PresidentialPardonForm]\t constructor called" << std::endl;
}

//	copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << "[PresidentialPardonForm]\tcopy constructor called" << std::endl;
}

//	copy assignment operator
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &source)
{
	std::cout << "[PresidentialPardonForm]\tcopy assignment operator called" << std::endl;

	if (this != &source)
	{
		AForm::operator=(source);
		_target = source._target;
	}
	return (*this);
}

//	destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm]\tdestructor called" << std::endl;
}

//	actions
void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!getSignature())
		throw AForm::FormNotSignedException();
		
	if (executor.getGrade() > getAuthzExec())
		throw AForm::GradeTooLowException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
