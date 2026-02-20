/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 09:14:00 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/20 12:36:49 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WRONGANIMAL_HPP
# define	WRONGANIMAL_HPP

#include <iostream>
#include <string>

class	WrongAnimal
{
	protected:

	std::string	type;

	public:

	//OCF
	WrongAnimal();
	WrongAnimal(const WrongAnimal &copy);
	WrongAnimal	&operator=(const WrongAnimal &source);
	~WrongAnimal();

	void			makeSound() const;	//	not declared virtual, c++ uses static binding at compile time
	std::string		getType() const;
};

#endif