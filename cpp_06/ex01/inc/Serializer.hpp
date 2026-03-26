/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:39:26 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 07:38:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SERIALIZE_HPP
# define	SERIALIZE_HPP

class	Serialize
{
	private:
	
	//OCF
	Serialize();
	Serialize(const Serialize &copy);
	Serialize	&operator=(const Serialize &source);
	~Serialize();

	public:

	static	uintptr_t serialize(Data* ptr);
	static	Data* deserialize(uintptr_t raw);
};




#endif