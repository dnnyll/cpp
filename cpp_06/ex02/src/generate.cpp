/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:22:15 by daniefe2          #+#    #+#             */
/*   Updated: 2026/04/10 08:12:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Base.hpp"
#include	"../inc/A.hpp"
#include	"../inc/B.hpp"
#include	"../inc/C.hpp"
#include	<cstdlib>

Base*	generate(void)
{
	int	decide = rand() % 3;

	if (decide == 0)
		return (new A);
	else if (decide == 1)
		return (new B);
	else if (decide == 2)
		return (new C);
	return (NULL);
}
