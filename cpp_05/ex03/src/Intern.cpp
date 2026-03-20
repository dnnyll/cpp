/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:21:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/20 16:21:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

//	constructor
Intern::Intern()
{
	std::cout << "[Intern]\tconstructor called" << std::endl;
}

//	copy constructor
Intern::Intern(const Intern &copy)
{
	std::cout << "[Intern]\tcopy constructor called" << std::endl;
	(void)copy;
}

//	copy assignment operator
Intern&	Intern::operator=(const Intern &source)
{
	std::cout << "[Intern]\tcopy assignment operator called" << std::endl;
	(void)source;
	return (*this);
}

//	destructor
Intern::~Intern()
{
	std::cout << "[Intern]\tdestructor called" << std::endl;
}

//	actions
AForm*	Intern::makeForm(const std::string& form, const std::string& target) const
{
	std::string names[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	
	AForm* (Intern::*creators[3])(const std::string&) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (form == names[i])
		{
			std::cout << "Intern creates " << names[i] << std::endl;
			return (this->*creators[i])(target);
		}
	}
	throw std::runtime_error("Unknown form type: " + form);
}

AForm*	Intern::createShrubbery(const std::string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomy(const std::string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidential(const std::string& target) const
{
	return (new PresidentialPardonForm(target));
}