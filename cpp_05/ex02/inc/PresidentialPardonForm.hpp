/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:40:13 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/20 14:22:33 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PRESIDENTIALPARDONFORM_HPP
# define	PRESIDENTIALPARDONFORM_HPP

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <iostream>
#include <string>

class	PresidentialPardonForm : public AForm
{
	private:
	
	std::string		_target;
	
	public:
	
	//	OCF
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
	virtual	~PresidentialPardonForm();

	//	actions
	virtual void	execute(Bureaucrat const& executor) const;
	
};

#endif