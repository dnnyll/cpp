/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:13:38 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/06 12:59:47 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Sed.hpp"

Sed::Sed(const std::string &fname, const std::string &search, const std::string &replace)
	: filename(fname), ss1(search), rs2(replace) {}

void	Sed::run() const
{
	if (ss1.empty())
	{
		std::cerr << "Error: search string cannot be empty.\n";
		return ;
	}

	//	open for reading
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: cannot open file " << filename << "\n";
		return ;
	}

	//	create the output file for writing
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: cannot create output file.\n";
		return ;
	}

	std::string		line;				//	holds each line from input file
	while (std::getline(infile, line))	// reads file line by line
	{
		std::string	result;
		size_t		pos = 0;	//	position of occurence
		size_t		last = 0;	//	tracker for string

		// finds all occurrences of ss1 in the current line
		while ((pos = line.find(ss1, last)) != std::string::npos)
		{
			result += line.substr(last, pos - last);
			result += rs2;
			last = pos + ss1.length();
		}
		result += line.substr(last);
		outfile << result;	//	write processed line to output file

		//	if !end add \n
		if (!infile.eof())
			outfile << "\n";
	}
	infile.close();
	outfile.close();
}
