/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:16:27 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/20 11:16:29 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WRONGCAT_HPP
# define	WRONGCAT_HPP

#include <string>
#include "../inc/WrongAnimal.hpp"

class	WrongCat : public WrongAnimal
{
	public:
	
	//OCF
	WrongCat();
	WrongCat(const WrongCat &copy);
	WrongCat	&operator=(const WrongCat &source);
	~WrongCat();

	void	makeSound() const;
};

#endif