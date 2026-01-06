/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:54:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/06 14:17:11 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	amplify(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
	{
		if(!isupper(argv[i])
		std::out << ""
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
		amplify(argv);
	return (0);
}