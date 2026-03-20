/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:49:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/20 10:35:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>
#include <string>

int	main()
{
	Bureaucrat	b1("Coy", 45);
	ShrubberyCreationForm a ("home");
	RobotomyRequestForm c ("drill");
	c.execute;
	b1.incrementGrade();
	b1.executeForm(a);
	b1.signForm(a);
	b1.executeForm(a);
	return (0);
}