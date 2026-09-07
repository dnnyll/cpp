#include	<string>
#include	<iostream>
#include	<cstdlib>
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

bool	PmergeMe::parseInput(const std::string &inputStr)
{
	int	currentPosition;
	int	inputSize;

	currentPosition = 0;
	inputSize = inputStr.size();

	while (currentPosition < inputSize)
	{
		if (!std::isdigit(inputStr[currentPosition]))
		{
			std::cerr << "remove this: Error: non numerical input detected." << std::endl;
			return (false);
		}
		if (std::isdigit(inputStr[currentPosition]) && currentPosition < inputSize)
		{
			if (inputStr[std::isdigit(currentPosition + 1)])
			{
				currentPosition++;
			}

			std::cout << currentPosition << std::endl;
		}
	}
	// _data.push_back(atoi(c_str(inputStr));
	// std::cout << inputStr[currentPosition - '0'] << std::endl;
	return (true);
}