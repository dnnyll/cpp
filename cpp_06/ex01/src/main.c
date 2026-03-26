/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:54:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 08:00:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Data.hpp"
#include	"../inc/Serializer.hpp"

int	main()
{
	Data	test;
	test.convertee = 77;
	Serializer::serialize(&test);
	return (0);
}