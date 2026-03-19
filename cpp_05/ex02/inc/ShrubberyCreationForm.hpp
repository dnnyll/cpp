/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:26:15 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/19 16:52:27 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include <iostream>
#include <string>

class	ShrubberyCreationForm : public AForm
{
	private:

	std::string	_target;

	public:
	
	//	OCF
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
	virtual	~ShrubberyCreationForm();

	//	actions
	virtual void	execute(Bureaucrat const& executor) const;

	
};