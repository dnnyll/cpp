#include	<string>
#include	<iostream>
#include	<cstdlib>
#include	<cerrno>
#include	<climits>
#include	"../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	#ifdef DEBUG
	std::cout << "[CONSTRUCTOR]\tcalled." << std::endl;
	#endif
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	#ifdef DEBUG
	std::cout << "[COPY CONSTRUCTOR]\tcalled." << std::endl;
	#endif

	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &input)
{
	#ifdef DEBUG
	std::cout << "[COPY A.OPER.]\tcalled." << std::endl;
	#endif

	if (this != &input)
		_data = input._data;
	return (*this);
}

PmergeMe::~PmergeMe()
{
	#ifdef DEBUG
	std::cout << "[DESTRUCTOR]\tcalled." << std::endl;
	#endif
}
bool	PmergeMe::getDuplicate(const int input)
{
	std::vector<int>::iterator	it;
	it = _data.begin();

	while (it != _data.end())
	{
		if(*it == input)
		{
			std::cerr << "Error: duplicate found for:\t" << *it << "." <<std::endl;
			return (true);
		}
		++it;
	}
	return (false);
}

bool	PmergeMe::parseInput(const std::string &inputStr)
{
	char	*endPtr;
	long	inputValue;

	errno = 0;
	inputValue = strtol(inputStr.c_str(), &endPtr, 10);

	if (*endPtr != '\0')
	{
		std::cerr << "Error: non numerical input detected." << std::endl;
		return (false);
	}
	if (errno == ERANGE || inputValue > INT_MAX || inputValue < 0)
	{
		std::cerr << "Error: value out of range." << std::endl;
		return (false);
	}

	if (getDuplicate(inputValue))
		return (false);

	_data.push_back(static_cast<int>(inputValue));

	// print debug
	// TO DO: move this away and/or add DEBUG flag
	std::vector<int>::iterator	it;
	
	it = _data.begin();
	
	while (it != _data.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	return (true);
}
