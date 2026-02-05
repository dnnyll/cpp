/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:13:38 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/05 14:35:34 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Sed.hpp"

Sed::Sed(const std::string &fname, const std::string &search, const std::string &replace)
	: filename(fname), s1(search), s2(replace) {}

void	Sed::run() const
{
	if (s1.empty())
	{
		std::cerr << "Error: search string cannot be empty.\n";
		return ;
	}

	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: cannot open file " << filename << "\n";
		return ;
	}

	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: cannot create output file.\n";
		return ;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		std::string result;
		size_t	pos = 0;
		size_t	last = 0;

		while ((pos = line.find(s1, last)) != std::string::npos)
		{
			result += line.substr(last, pos - last);	// text before s1
			result += s2;								// replacement
			last = pos + s1.length();
		}
		result += line.substr(last);					// append remainder
		outfile << result;
		if (!infile.eof())
			outfile << "\n";							// preserve line breaks
	}
	infile.close();
	outfile.close();
}
