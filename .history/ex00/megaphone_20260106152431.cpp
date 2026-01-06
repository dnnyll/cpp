/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:54:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/06 15:24:31 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	amplify(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		std::cout << (char)std::toupper(argv[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if(argc < 2)
	{
		std::cerr << "ARTICULATE!" << std::endl;
		return (1);
	}
	else
	{
		while (argv[i])
		{
			amplify(argv[i]);
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}