/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:50:34 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/27 11:02:28 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TEMPLATEARRAY_HPP
# define	TEMPLATEARRAY_HPP

#include	<iostream>

template<typename T>
class	Array
{
	private:
	
	T*				_array;
	unsigned int	_size;
	
	public:
	
	Array();
	Array(const Array &source);
	Array	&operator=(const Array &source);
	~Array();
};

#include	"../src/Array.tpp"

#endif
