/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 08:59:31 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/30 11:53:11 by daniefe2         ###   ########.fr       */
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

	{
		std::cout << "\n_________start deep copy test" << std::endl;
		Array<int>	original(3);

		original[0] = 1444;
		original[1] = 77;
		original[2] = 252525;
		
		Array<int>	copy(original);
		copy[1] = 71;
		
		std::cout << "size =\t" << original.getSize() << std::endl;
		std::cout << original.getArray()[0] << std::endl;
		std::cout << original.getArray()[1] << std::endl;
		std::cout << original.getArray()[2] << std::endl;
		std::cout << "\n";
		std::cout << "size =\t" << copy.getSize() << std::endl;
		std::cout << copy.getArray()[0] << std::endl;
		std::cout << copy.getArray()[1] << std::endl;
		std::cout << copy.getArray()[2] << std::endl;
		
		std::cout << "_________end deep copy test\n" << std::endl;
	}
	
	{
		std::cout << "\n_________start copy assign. operator test" << std::endl;
		Array<int>	array1Int(2);

		array1Int[0] = 1444;
		array1Int[1] = 77;
		
		Array<int>	array2Int(2);
		array2Int = array1Int;
		
		std::cout << "size =\t" << array1Int.getSize() << std::endl;
		std::cout << array1Int.getArray()[0] << std::endl;
		std::cout << array1Int.getArray()[1] << std::endl;
		std::cout << "\n";
		array2Int[0] = 1111;
		std::cout << "size =\t" << array2Int.getSize() << std::endl;
		std::cout << array2Int.getArray()[0] << std::endl;
		std::cout << array2Int.getArray()[1] << std::endl;
		
		std::cout << "_________end copy assign. operator test\n" << std::endl;
	}

	{
		std::cout << "\n_________start out of bounds test" << std::endl;
		Array<int>	arrayInt(1);

		try
		{
			arrayInt[9] = 17;
			std::cout << arrayInt.getArray()[9] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << "error: exception caught\t" << e.what() << std::endl;
		}
		
		std::cout << "_________end out of bounds test\n" << std::endl;
	}
	return (0);
}