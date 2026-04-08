/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:50:34 by daniefe2          #+#    #+#             */
/*   Updated: 2026/04/08 14:30:33 by daniefe2         ###   ########.fr       */
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
	
		//	OCF
		Array();
		Array(unsigned int n);
		Array(const Array &source);
		Array	&operator=(const Array &source);
		~Array();

		//	methods
		T*	getArray();
		unsigned int	getSize() const;
		const T& operator[](unsigned int inputIndex) const;
		T& operator[](unsigned int inputIndex);

	class	OutBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("error :index out of bounds");
			}
	};
};

#include	"../src/Array.tpp"

#endif
