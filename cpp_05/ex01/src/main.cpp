/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:49:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 11:53:15 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"
#include <iostream>
#include <string>

int	main()
{
	std::cout << "\n==========\tForm Creation Tests\t==========\n" << std::endl;
	
	std::cout << "Successful Boundry Grade\n" << std::endl;
	try
	{
		Form	a("Form A", 147, 72);
		std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	std::cout << "\nLow Boundry Signing Grade\n" << std::endl;
	try
	{
		Form	b("Form B", 151, 50);
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nHigh Boundry Signing Grade\n" << std::endl;
	try
	{
		Form	c("Form C", 0, 50);
		std::cout << c << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
///////////////////////////////////////////////////////////////////////////////////////////////

	std::cout << "\n==========\tInvalid authorization\t==========\n" << std::endl;
	
	std::cout << "Insufficient Grade to sign\n" << std::endl;
	
	try
	{
		Form d("Form D", 33, 2);
		std::cout << d << std::endl;

		Bureaucrat b1("Coy", 75);
		std::cout << b1 << std::endl;

		b1.signForm(d);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nIncrement Grade to sign\n" << std::endl;
	try
	{
		Form d("Form D", 15, 13);
		std::cout << d << std::endl;

		Bureaucrat b1("Stacey", 16);
		std::cout << b1 << std::endl;

		b1.signForm(d);

		b1.incrementGrade();
		std::cout << b1 << std::endl;

		b1.signForm(d);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\nDecrement Grade to sign\n" << std::endl;
	try
	{
		Form d("Form D", 15, 13);
		std::cout << d << std::endl;

		Bureaucrat b1("Stacey", 15);
		std::cout << b1 << std::endl;

		b1.signForm(d);

		b1.decrementGrade();
		std::cout << b1 << std::endl;

		b1.signForm(d);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}