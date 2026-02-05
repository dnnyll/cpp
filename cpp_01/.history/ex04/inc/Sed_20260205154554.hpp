/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 12:38:21 by daniefe2          #+#    #+#             */
/*   Updated: 2026/02/05 15:45:54 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <string>

class	Sed
{
	private:
		std::string	filename;
		std::string	s1;
		std::string	s2;

	public:
		Sed(const std::string &fname, const std::string &search, const std::string &replace);
		void	run() const;
};

#endif
