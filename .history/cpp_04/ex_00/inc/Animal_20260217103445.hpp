/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:14:00 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/17 10:34:45 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

class	Animal
{
	protected:

	std::string	type;

	public:

	//OCF
	Animal(const std::string &inputName);
	Animal(const Animal &copy);
	Animal	&operator=(const Animal &source);
	~Animal();

	
};

#endif