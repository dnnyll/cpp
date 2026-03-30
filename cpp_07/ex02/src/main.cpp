/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:59:31 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/30 09:27:35 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Array.hpp"
#include	<string>

int	main()
{
	Array<int>			emptyInt;
	Array<std::string>	emptyString;
	Array<float>		emptyFloat;

	Array<int>			testInt(2);
	testInt[0] = 77;
	testInt[1] = 1444;
	
	std::cout << emptyInt.getArray() << std::endl; 
	std::cout << testInt.getArray()[0] << std::endl;
	std::cout << testInt.getArray()[1] << std::endl;
	
	std::cout << emptyString.getArray() << std::endl; 
	std::cout << emptyFloat.getArray() << std::endl; 



	return (0);
}