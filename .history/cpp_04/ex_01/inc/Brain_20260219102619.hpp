/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:12:40 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 10:26:19 by daniefe2         ###   ########.fr       */
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
	B();
	B(const B &copy);
	B	&operator=(const B &source);
	virtual	~B();
	private:
};





#endif