/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:12:40 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/19 10:27:56 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BRAIN_HPP
# define	BRAIN_HPP

#include <string>

class Brain
{
	private:
	
	std::string	ideas[100];
	
	public:
	
	//OCF
	Brain();
	Brain(const Brain &copy);
	Brain	&operator=(const Brain &source);
	virtual	~Brain();

	void		setIdea(int index, const std::string &idea);
	std::string	getIdea(int i);

};





#endif