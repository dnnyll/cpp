/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:30:32 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 10:34:15 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP
# define	CAT_HPP

#include "../inc/Animal.hpp"

class	Cat : public Animal
{
	public:
	
	//OCF
	Cat(const std::string &inputName);
	Cat(const Cat &copy);
	Cat	&operator=(const Cat &source);
	~Cat();

};

#endif