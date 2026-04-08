/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:02:17 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/30 09:37:25 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/TemplateOperations.hpp"
#include	<iostream>
#include	<string>

void	incrementor(int &input)
{
	input++;
}

void capitalizor(char &input)
{
	input = std::toupper(input);
}

int	main()
{
	int	array[3] = {5, 25, 101};
	
	iter(array, 3, incrementor);
	iter(array, 3, print<int>);

	std::string	str = "abcdef";
	iter(&str[0], str.length(), capitalizor);
	iter(&str[0], str.length(), print<char>);

	return (0);
}