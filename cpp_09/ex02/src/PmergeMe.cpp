#include	<string>
#include	<iostream>
#include	<cstdlib>
#include	<cerrno>
#include	<climits>
#include	<vector>
#include	<deque>
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

std::vector<int>	PmergeMe::sortVector(std::vector<int> inputData)
{
	int		straggler;
	bool	hasStraggler;
	size_t	i;

	straggler = -1;
	hasStraggler = false;
	i = 0;

	if(inputData.size() <= 1)
		return (inputData);
	
	std::vector<std::pair<int, int> > pairs = pairVector(inputData, straggler, hasStraggler);
	
	while (i < pairs.size())
	{
		std::cout << "pair: (" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;

		if (hasStraggler)
				std::cout << "straggler: " << straggler << std::endl;

		i++;
	}
	
	// next: extract "large" values, recurse, etc.
	
	return (inputData);
}

std::deque<int>		PmergeMe::sortDeque(std::deque<int> inputData)
{
	return(inputData);
}

bool	PmergeMe::sortData()
{
	_data = sortVector(_data);
	return (true);
}

std::vector<std::pair<int, int> >	PmergeMe::pairVector(const std::vector<int> &input, int &straggler, bool &hasStraggler)
{

	std::vector<std::pair<int, int> >	pairs;
	
	int		i;
	int		a;
	int		b;
	int		inputSize;

	i = 0;
	inputSize = input.size();

	while (i + 1 < inputSize)
	{
		a = input[i];
		b = input[i + 1];

		if (a < b)
			pairs.push_back(std::pair<int, int>(a, b));
		else
			pairs.push_back(std::pair<int, int>(b, a));

		i += 2;
	}

	if (inputSize % 2 == 1)
	{
		std::cout << "hasStraggler = true" << std::endl;
		straggler = input[inputSize - 1];
		hasStraggler = true;
	}
	else
	{
		std::cout << "hasStraggler = false" << std::endl;
		hasStraggler = false;
	}
	return (pairs);
}

// ┌───────────────────────────────────────────────────────────────┐
// │ pairVector(input, straggler, hasStraggler)                       │
// ├───────────────────────────────────────────────────────────────┤
// │ - create empty vector<pair<int,int>> pairs                       │
// │ - i = 0                                                            │
// │ - while i + 1 < input.size():                                     │
// │     a = input[i], b = input[i+1]                                  │
// │     if a < b: pairs.push_back( (a, b) )   // (small, large)       │
// │     else:     pairs.push_back( (b, a) )                           │
// │     i += 2                                                         │
// │ - if input.size() is odd:                                         │
// │     straggler = input[input.size()-1]                             │
// │     hasStraggler = true                                            │
// │   else:                                                            │
// │     hasStraggler = false                                           │
// │ - return pairs                                                     │
// └───────────────────────────────────────────────────────────────┘

