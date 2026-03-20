/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:49:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/20 13:46:35 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

int	main()
{
	std::cout << "\n==========\tShrubbery Test\t==========\n" << std::endl;
	{
		try
		{
			Bureaucrat	b1("Coy", 30);
			ShrubberyCreationForm a ("home");
		
			b1.incrementGrade();
			b1.executeForm(a);
			b1.signForm(a);
			b1.executeForm(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	
	std::cout << "\n==========\tRobotomy Test\t==========\n" << std::endl;
	{
		try
		{
			Bureaucrat	b2("Coy", 45);
			RobotomyRequestForm b ("drill");
			b2.signForm(b);
			b2.executeForm(b);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	
	std::cout << "\n==========\t==========\t==========\n" << std::endl;
	{
		Bureaucrat	b2("Coy", 1);
		RobotomyRequestForm b("target");

		b2.signForm(b);

		for (int i = 0; i < 5; i++)
			b2.executeForm(b);
	}
	
	std::cout << "\n==========\tPresidential Test\t==========\n" << std::endl;
	{
		try
		{
			Bureaucrat	b3("Coy", 1);
			PresidentialPardonForm c ("Coy");
			b3.signForm(c);
			b3.executeForm(c);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}

	std::cout << "\n==========\tPolymorphism Test\t==========\n" << std::endl;
	{
		try
		{
			Bureaucrat	b4("Poly", 1);
			AForm*	d = new ShrubberyCreationForm("poly_home");

			b4.signForm(*d);
			b4.executeForm(*d);

			delete d;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}