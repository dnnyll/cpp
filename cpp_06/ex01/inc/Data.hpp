/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:39:26 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/25 14:52:15 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DATA_HPP
# define	DATA_HPP

class	Data
{
	private:
	
	//OCF
	Data();
	Data(const Data &copy);
	Data	&operator=(const Data &source);
	~Data();

	public:

	
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};




#endif