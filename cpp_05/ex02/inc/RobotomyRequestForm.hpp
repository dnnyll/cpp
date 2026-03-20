/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:39:48 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/20 10:33:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	RobotomyRequestForm: Required grades: sign 72, exec 45
	Makes some drilling noises, then informs that <target> has been robotomized
	successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/

#ifndef		ROBOTOMYREQUESTFORM
# define	ROBOTOMYREQUESTFORM

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <string>

class	RobotomyRequestForm : AForm
{
	private:
	
	std::string		_target;
	
	public:
	
	//	OCF
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
	virtual	~RobotomyRequestForm();

	//	actions
	virtual void	execute(Bureaucrat const& executor) const;
	
};

#endif