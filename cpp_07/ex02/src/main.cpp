/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:59:31 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/30 10:39:48 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Array.hpp"
#include	<string>

int	main()
{
	{
		std::cout << "\n_________start empty int test" << std::endl;
		Array<int>	emptyInt;

		std::cout << "size =\t" << emptyInt.getSize() << std::endl;
		std::cout << emptyInt.getArray() << std::endl; 
		std::cout << "_________end empty int test\n" << std::endl;
	}
	
	{
		std::cout << "\n_________start size empty int test" << std::endl;
		Array<int>	sizeInt(3);

		std::cout << "size =\t" << sizeInt.getSize() << std::endl;
		std::cout << sizeInt.getArray()[0] << std::endl;
		std::cout << sizeInt.getArray()[1] << std::endl;
		std::cout << sizeInt.getArray()[2] << std::endl;

		std::cout << "_________end size empty int test\n" << std::endl;
	}

		{
		std::cout << "\n_________start size int test" << std::endl;
		Array<int>	sizeInt(3);

		sizeInt[0] = 1444;
		sizeInt[1] = 77;
		sizeInt[2] = 252525;
		
		std::cout << "size =\t" << sizeInt.getSize() << std::endl;
		std::cout << sizeInt.getArray()[0] << std::endl;
		std::cout << sizeInt.getArray()[1] << std::endl;
		std::cout << sizeInt.getArray()[2] << std::endl;

		std::cout << "_________end size int test\n" << std::endl;
	}
	return (0);
}