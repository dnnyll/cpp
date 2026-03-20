/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 14:21:24 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/20 16:01:43 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		INTERN_HPP
# define	INTERN_HPP

#include <string>

class	AForm;

class	Intern
{
	private:

	AForm*	createShrubbery(const std::string& target) const;
	AForm*	createRobotomy(const std::string& target) const;
	AForm*	createPresidential(const std::string& target) const;
	
	public:
	
	//	OCF
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& copy);
	virtual	~Intern();

	//	actions
	AForm*	makeForm(const std::string& form, const std::string& target) const;
};

#endif