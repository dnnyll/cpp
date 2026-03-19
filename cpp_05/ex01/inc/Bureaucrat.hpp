/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 09:30:19 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 10:04:56 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		Bureaucrat_HPP
# define	Bureaucrat_HPP

#include "../inc/Form.hpp"
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
	void	signForm(Form& input) const;

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