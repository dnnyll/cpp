/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:39:48 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/20 11:21:57 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ROBOTOMYREQUESTFORM
# define	ROBOTOMYREQUESTFORM

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <string>

class	RobotomyRequestForm : public AForm
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