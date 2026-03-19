/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:49:07 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 10:09:12 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FORM_HPP
# define	FORM_HPP

#include <iostream>
#include <string>

class	Bureaucrat;

class	Form
{
	private:
	
	std::string const	_name;
	bool				_signature;
	int const			_authzSign;
	int const			_authzExec;

	public:
	
	//	OCF
	Form(const std::string& name, int const authzSign, int const authzExec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	//	accessors
	const	std::string& getName() const;
	bool	getSignature() const;
	int		getAuthzSign() const;
	int		getAuthzExec() const;

	//	actions
	void	beSigned(const Bureaucrat& input);
	
	//	exceptions
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
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif