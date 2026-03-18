/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:49:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/18 13:40:32 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	std::cout << "\n==========\tBureaucrat Creation Tests\t==========\n" << std::endl;
	try
	{
		Bureaucrat	b1("Roger", 2);
		std::cout << b1 << std::endl;

		Bureaucrat	b2("Bob", 151);	//	throw GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b3("Jodie", 0);	//	throw GradeTooHighException
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////

	std::cout << "\n==========\tGrade Modification Tests\t==========\n" << std::endl;
	try
	{
		Bureaucrat	b4("Renata", 149);
		std::cout << b4 << std::endl;

		b4.incrementGrade();		//	149 → 148
		std::cout << "After increment: " << b4 << std::endl;

		b4.decrementGrade();		//	148 → 149
		std::cout << "After decrement: " << b4 << std::endl;

		b4.decrementGrade();		//	149 → 150
		std::cout << "After decrement to 150: " << b4 << std::endl;

		b4.decrementGrade();		//	throw GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

///////////////////////////////////////////////////////////////////////////////////////////////
	
	// std::cout << "\n==========\tCopy & Assignment Tests\t==========\n" << std::endl;
	// try
	// {
	// 	Bureaucrat original("Diana", 10);
	// 	Bureaucrat copy(original); // Copy constructor
	// 	Bureaucrat assigned("Samantha", 50);
	// 	assigned = original;      // Assignment operator

	// 	std::cout << "Original: " << original << std::endl;
	// 	std::cout << "Copy: " << copy << std::endl;
	// 	std::cout << "Assigned: " << assigned << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cout << "Exception caught: " << e.what() << std::endl;
	// }

///////////////////////////////////////////////////////////////////////////////////////////////

	std::cout << "\n==========\tBoundary Tests\t==========\n" << std::endl;
	try
	{
		Bureaucrat	top("Coy", 1);
		Bureaucrat	bottom("Hank", 150);

		std::cout << top << std::endl;
		top.incrementGrade();			//	throw GradeTooHighException
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught at top: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bottom("Hank", 150);
		bottom.decrementGrade();		//	throw GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught at bottom: " << e.what() << std::endl;
	}
	return (0);
}