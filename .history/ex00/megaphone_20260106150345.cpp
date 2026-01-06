/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:54:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/06 15:03:45 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	amplify(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(argv[i][j])
	{
		j = 0;
		while (argv[j])
		toupper(argv[i++]);
	}
}

int	main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cerr << "ARTICULATE!" << std::endl;
		return (1);
	}
	else
	{
		while (*args != NULL)
	}
		amplify(argv);
	return (0);
}