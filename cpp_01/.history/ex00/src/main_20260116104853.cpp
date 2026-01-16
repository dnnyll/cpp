/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:23:45 by daniefe2          #+#    #+#             */
/*   Updated: 2026/01/16 10:48:53 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

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
	std::cout << "silent message, Randy has been created

	B.announce();
	randomChump("Timmy");
	A.announce();
	delete C;
}