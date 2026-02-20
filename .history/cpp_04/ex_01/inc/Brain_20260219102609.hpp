/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:12:40 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 10:26:09 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BRAIN_HPP
# define	BRAIN_HPP

#include <string>

class Brain
{
	public:
	
	std::string	ideas[100];

	//OCF
	Cat();
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &source);
	virtual	~Cat();
	private:
};





#endif