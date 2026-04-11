/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateOperations.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:53:27 by daniefe2          #+#    #+#             */
/*   Updated: 2026/04/11 10:55:10 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TEMPLATEOPERATIONS_HPP
# define	TEMPLATEOPERATIONS_HPP

#include	<iostream>
#include	<cstddef>

//	non-const version
template<typename T, typename F>
void	iter(T *array, const size_t length, F function)
{
	size_t	i = 0;

	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

//	const version
template<typename T, typename F>
void	iter(const T *array, const size_t length, F function)
{
	size_t	i = 0;

	while (i < length)
	{
		function(array[i]);
		i++;
	}
}
#endif
