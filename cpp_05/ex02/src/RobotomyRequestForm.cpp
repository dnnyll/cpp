/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:31:04 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 15:33:21 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <fstream>

//	constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "[RobotomyRequestForm]\t constructor called" << std::endl;
}

//	copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << "[RobotomyRequestForm]\tcopy constructor called" << std::endl;
}

//	copy assignment operator
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	std::cout << "[RobotomyRequestForm]\tcopy assignment operator called" << std::endl;

	if (this != &source)
	{
		AForm::operator=(source);
		_target = source._target;
	}
	return (*this);
}

//	destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm]\tdestructor called" << std::endl;
}

//	actions
void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getSignature())
		throw AForm::FormNotSignedException();
		
	if (executor.getGrade() > getAuthzExec())
		throw AForm::GradeTooLowException();

	std::cout << "Drilling Noises" << std::endl;
	
	if(rand() % 2 == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
	return ;
}