/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:31:04 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 17:07:33 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <fstream>

//	constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "[ShrubberyCreationForm]\t constructor called" << std::endl;
}

//	copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << "[ShrubberyCreationForm]\tcopy constructor called" << std::endl;
}

//	copy assignment operator
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
	std::cout << "[ShrubberyCreationForm]\tcopy assignment operator called" << std::endl;

	if (this != &source)
	{
		AForm::operator=(source);
		_target = source._target;
	}
	return (*this);
}

//	destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm]\tdestructor called" << std::endl;
}

//	actions
void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (!getSignature())
		throw AForm::FormNotSignedException();
		
	if (executor.getGrade() > getAuthzExec())
		throw AForm::GradeTooLowException();
		
	std::ofstream outfile((_target + "_Shrubbery").c_str());
	
	if (!outfile)
	{
		std::cerr << "Failed to open file." << std::endl;
		return ;
	}
	
	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{   (o)   (o)   }" << std::endl;
	outfile << " \\     |||     /" << std::endl;
	outfile << "     ~  |||  ~" << std::endl;
	outfile << "  _- -  |||  _- _" << std::endl;
	outfile << "    _ - |||   -_" << std::endl;
	outfile << "       |||" << std::endl;
	outfile << "      |||" << std::endl;
	outfile << "      |||" << std::endl;
	outfile << "      |||" << std::endl;
	outfile << "      |||" << std::endl;
	
	outfile.close();
}
