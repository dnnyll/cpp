/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:54:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/06 15:17:08 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	print(char *argv)
{
	std:cout << (char)std::toupper(*argv);
}

int	amplify(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		print(argv[i]);
	}
	
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
	return (0);
}