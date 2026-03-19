/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:30:19 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 15:21:31 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		Bureaucrat_HPP
# define	Bureaucrat_HPP

#include "../inc/AForm.hpp"
#include <iostream>
#include <string>

class	Bureaucrat
{
	private:

	std::string const	_name;
	int					_grade;

	public:

	//	OCF
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	//	accessors
	const	std::string& getName() const;
	int		getGrade() const;

	//	actions
	void	incrementGrade();
	void	decrementGrade();
	void	signForm(AForm& input) const;
	void	executeForm(AForm const & form) const;

	// exceptions
	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

//	operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif