/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:05:40 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 15:25:28 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AFORM_HPP
# define	AFORM_HPP

#include <iostream>
#include <string>

class	Bureaucrat;

class	AForm
{
	private:
	
	std::string const	_name;
	bool				_signature;
	int const			_authzSign;
	int const			_authzExec;

	public:
	
	//	OCF
	AForm(const std::string& name, int const authzSign, int const authzExec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual	~AForm();

	//	accessors
	const	std::string& getName() const;
	bool	getSignature() const;
	int		getAuthzSign() const;
	int		getAuthzExec() const;
	
	//	actions
	void			beSigned(const Bureaucrat& input);
	virtual void	execute(Bureaucrat const& executor) const = 0;
	
	//	exceptions
	class	GradeTooHighException : public std::exception
	{
		public:

		const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
		public:

		const char* what() const throw();
	};
	class	FormNotSignedException : public std::exception
	{
		public:

		const char* what() const throw();
	};
};

//	operator overload
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif