/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:54:03 by daniefe2          #+#    #+#             */
/*   Updated: 2026/04/10 10:05:36 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Data.hpp"
#include	"../inc/Serializer.hpp"
#include	<iostream>

/*
	serializes a memory address to a raw integer and deserializes it back
	verifies that the address and data are preserved through the process

	uintptr_t is an unsigned integer, it's large enough to hold
	any pointer value.

	test		→ the actual object, lives at some address, holds intValue = 777
	original	→ holds the address of test (not the data itself)
	raw			→ holds that same address, but typed as a plain integer
	result		→ holds that same address again, typed back as Data*
*/

int	main()
{
	{
		Data		test;
		
		test.intValue = 777;
		std::cout << "test intValue = 777" << std::endl;

		Data*		original = &test;						//	pointer to test
		uintptr_t	raw = Serializer::serialize(original);	//	pointer -> integer
		Data*		result = Serializer::deserialize(raw);	//	integer -> pointer

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

/*

STACK MEMORY
┌─────────────────────────────────┐
│  Data test                      │
│  ┌───────────────────────────┐  │
│  │  intValue = 777           │  │
│  └───────────────────────────┘  │
│  address: 0x7ffee4b2c           │
└─────────────────────────────────┘
        ▲                ▲
        │                │
        │                │
┌───────────────┐        │
│ Data* original│        │
│ 0x7ffee4b2c   │        │
└───────────────┘        │
        │                │
        │ serialize()    │
        ▼                │
┌───────────────┐        │ deserialize()
│ uintptr_t raw │        │
│ 0x7ffee4b2c   │        │
└───────────────┘        │
        │                │
        │                │
        ▼                │
┌───────────────┐        │
│ Data* result  │────────┘
│ 0x7ffee4b2c   │
└───────────────┘

*/
