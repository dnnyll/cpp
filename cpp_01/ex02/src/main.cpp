/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:27:25 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 15:55:47 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
#include <iostream>


int	main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
	{
		std::cerr << "Please run the program without arguments." << std::endl;
		return (1);
	}
	//	string variable
	//	str			:	Actual string variable in memory.
	//					Holds value "HI THIS IS BRAIN".
	//					Address can be accessed with &str.
	std::string	str = "HI THIS IS BRAIN";

	//	pointer to string
	//	stringPTR	:	Pointer storing the address of str.
	//					Access value with *stringPTR.
	//					Can be nullptr or reassigned.
	std::string	*stringPTR = &str;

	//	reference to string
	//	stringREF	:	Reference (alias) to str. 
	//					Access value like str. 
	//					Cannot be null or reassigned.
	//					Shares str's memory address.
	std::string	&stringREF = str;

	std::cout << std::endl;
	std::cout << "Memory address of str:\t\t\t" << &str << std::endl;
	std::cout << "Value of str:\t\t\t\t" << str << std::endl;
	std::cout << std::endl;
	std::cout << "Memory address held by stringSTR:\t" << stringPTR << std::endl;
	std::cout << "Value of stringSTR:\t\t\t" << *stringPTR << std::endl;
	std::cout << std::endl;
	std::cout << "Memory address held by stringREF:\t" << &stringREF << std::endl;
	std::cout << "Value of stringREF:\t\t\t" << stringREF << std::endl;
	return (0);
}