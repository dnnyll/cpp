/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateOperations.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:53:27 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 15:14:39 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		TEMPLATEOPERATIONS_HPP
# define	TEMPLATEOPERATIONS_HPP

#include	<iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T	temp;
	
	temp = a;
	a = b;
	b = temp;
}
template<typename T>
T	min(T &a, T &b)
{
	if (a == b)
		return (b);
	else if (a < b)
		return (a);
	else
		return (b);

}
template<typename T>
T	max(T &a, T &b)
{
	if (a == b)
		return (b);
	else if (a > b)
		return (a);
	else
		return (b);
}

#endif
