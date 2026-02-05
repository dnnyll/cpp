/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:13:38 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/05 14:43:47 by daniefe2         ###   ########.fr       */
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

	std::string	line;  //	holds each line from input file
	while (std::getline(infile, line))  // read file line by line
	{
		std::string	result;  // string to build the processed line
		size_t	pos = 0;      // position of the found search string
		size_t	last = 0;     // tracks start of the next substring to append

		// Find all occurrences of s1 in the current line
		while ((pos = line.find(s1, last)) != std::string::npos)
		{
			// Append text from 'last' to the start of the found s1
			result += line.substr(last, pos - last);

			// Append the replacement string s2
			result += s2;

			// Move 'last' past the found s1
			last = pos + s1.length();
		}

		// Append the remainder of the line after the last occurrence of s1
		result += line.substr(last);

		// Write the processed line to the output file
		outfile << result;

		// Add a newline if we are not at the end of the input file
		if (!infile.eof())
			outfile << "\n";  // preserve line breaks
	}

	// Close the files (optional since destructors do it automatically)
	infile.close();
	outfile.close();
}
