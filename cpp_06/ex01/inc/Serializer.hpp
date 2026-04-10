/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:39:26 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 07:38:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SERIALIZE_HPP
# define	SERIALIZE_HPP

#include	"../inc/Data.hpp"
#include	<stdint.h> 

class	Serializer
{
	private:
	
		//	OCF
		Serializer();
		Serializer(const Serializer &copy);
		Serializer	&operator=(const Serializer &source);
		~Serializer();

	public:

		//	methods
		static	uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
};

#endif
