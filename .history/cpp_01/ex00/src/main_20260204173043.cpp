/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:23:45 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/04 17:30:43 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inmain.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
	{
		std::cerr << "Please run the program without arguments." << std::endl;
		return (1);
	}
	
	Zombie	A("Terrence");
	Zombie	B("Phillip");
	Zombie*	C = newZombie("Randy");
	std::cout	<< "\033[38;2;41;41;41m\033[9m"
				<< "Terrence, Phillip and Randy has been created"
				<<	"\033[0m"
				<<std::endl;

	B.announce();
	randomChump("Timmy");
	A.announce();
	delete C;
}