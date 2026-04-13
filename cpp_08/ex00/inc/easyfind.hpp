#ifndef		EASYFIND_HPP
# define	EASYFIND_HPP

#include	<iostream>
#include	<algorithm>

//	non-const version
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	std::cout << "[non-const iterator]" << std::endl;
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("value not found");
	return (it);
}

//	const version
template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	std::cout << "[const_iterator]" << std::endl;
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("value not found");
	return it;
}

////	my own find with typename T for any type of var
// template <typename T>
// typename T::iterator	easyfind(T &container, typename T::value_type value)
// {
// 	typename T::iterator	it;
	
// 	it = container.begin();

// 	while (it != container.end())
// 	{
// 		if (*it == value)
// 			return (it);
// 		++it;
// 	}
// 	throw	std::runtime_error("value not found");
// }

#endif
