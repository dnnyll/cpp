/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:02:17 by daniefe2          #+#    #+#             */
/*   Updated: 2026/04/11 10:55:58 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/TemplateOperations.hpp"
#include	<iostream>
#include	<string>

template<typename T>
void incrementor(T &input)
{
	input++;
}

template<typename T>
void	print(const T &input)
{
	std::cout << input << std::endl;
}

void	capitalizor(char &input)
{
	input = std::toupper(input);
}

int	main()
{
	int				array[3] = {5, 25, 101};
	double			array1[3] = {7.1, 7.2, 7.3};
	const double	array2[3] = {1.1, 1.2, 1.3};

	iter(array, 3, incrementor<int>);
	iter(array, 3, print<int>);
	
	iter(array1, 3, incrementor<double>);
	iter(array1, 3, print<int>);

	iter(array2, 3, print<double>);
	
	std::string	str = "abcdef";
	iter(&str[0], str.length(), capitalizor);
	iter(&str[0], str.length(), print<char>);

	return (0);
}
