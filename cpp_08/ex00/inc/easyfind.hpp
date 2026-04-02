#ifndef		EASYFIND_HPP
# define	EASYFIND_HPP

#include	<iostream>

template <typename T>
typename T::iterator	easyfind(T &container, typename T::value_type value)
{
	typename T::iterator	it;
	
	it = container.begin();

	while (it != container.end())
	{
		if (*it == value)
			return (it);
		++it;
	}
	throw	std::runtime_error("value not found");
}

#endif
