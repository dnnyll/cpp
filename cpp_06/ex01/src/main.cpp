/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:54:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/26 09:45:04 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Data.hpp"
#include	"../inc/Serializer.hpp"
#include	<iostream>

int	main()
{
	{
		Data		test;
		
		test.intValue = 777;
		std::cout << "test intValue = 777" << std::endl;

		Data*		original = &test;
		uintptr_t	raw = Serializer::serialize(original);
		Data*		result = Serializer::deserialize(raw);

		std::cout << "original address:\t"	<< original << std::endl;
		std::cout << "result address:\t\t"	<< result << std::endl;
		
		if (result->intValue == 777)
			std::cout << "success: data integrity verified" << std::endl;
		else
			std::cout << "error: data corrupted" << std::endl;
			
		if (original == result)
			std::cout << "success: pointers match" << std::endl;
		else
			std::cout << "error: pointers do not match" << std::endl;
	}
	return (0);
}
