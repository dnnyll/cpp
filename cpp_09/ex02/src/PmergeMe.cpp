#include	<string>
#include	<iostream>
#include	<cstdlib>
#include	<cerrno>
#include	<climits>
#include	<vector>
#include	<deque>
#include	<algorithm>
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


/*

┌───────────────────────────────────────────────────────────────┐
│ sortVector(inputData)                                         │
├───────────────────────────────────────────────────────────────┤
│ 1. base case (done)                                           │
│ 2. pairs = pairVector(...)              (done)                │
│ 3. largeValues = extract .second from each pair    <- NEXT    │
│ 4. mainChain = sortVector(largeValues)  (recursive call)      │
│ 5. ... (association tracking, insertion — later steps)        │
└───────────────────────────────────────────────────────────────┘

*/

// recursion
std::vector<int>	PmergeMe::sortVector(std::vector<int> inputData)
{
	int		straggler;
	bool	hasStraggler;
	size_t	i;

	straggler = -1;
	hasStraggler = false;
	i = 0;

	if (inputData.size() <= 1)
		return (inputData);

	std::vector<std::pair<int, int> > pairs = pairVector(inputData, straggler, hasStraggler);

	//	print debug
	while (i < pairs.size())
	{
		std::cout << "pair: (" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;

		if (hasStraggler)
				std::cout << "straggler: " << straggler << std::endl;

		i++;
	}

	// find and gather largerValues
	std::vector<int>	largerValues;

	i = 0;

	while (i < pairs.size())
	{
		largerValues.push_back(pairs[i].second);
		i++;
	}

	// this is the sorted vector of large values, then we need to insert smaller values in it
	std::vector<int> mainChain = sortVector(largerValues);

	// find and gather smallerValues
	std::vector<std::pair<int, int> > smallerValues;

	i = 0;

	while (i < pairs.size())
	{
		std::vector<int>::iterator position = std::find(mainChain.begin(), mainChain.end(), pairs[i].second);

		int index;

		index = position - mainChain.begin();

		smallerValues.push_back(std::pair<int, int>(pairs[i].first, index));
		i++;
	}

	// find smaller value to insert in the chain
	size_t	j;

	j = 0;
	while (j < smallerValues.size())
	{
		if (smallerValues[j].second == 0)
			break ;
		j++;
	}

	mainChain.insert(mainChain.begin(), smallerValues[j].first);
	smallerValues.erase(smallerValues.begin() + j);

	// mainChain shifted right by 1 after front insertion,
	// so every stored index in smallerValues is now off by one — correct it
	size_t	k;

	k = 0;
	while (k < smallerValues.size())
	{
		smallerValues[k].second += 1;
		k++;
	}

	// apply jacobsthalOrder to the remaining smallerValues
	std::vector<int> insertOrder = jacobsthalOrder(smallerValues.size());

	// debug: state of mainChain and remaining smallerValues after front insertion
	std::cout << "mainChain after front insert: ";
	size_t	p;

	p = 0;
	while (p < mainChain.size())
	{
		std::cout << mainChain[p] << " ";
		p++;
	}
	std::cout << std::endl;

	std::cout << "smallerValues remaining: ";
	p = 0;
	while (p < smallerValues.size())
	{
		std::cout << "(" << smallerValues[p].first << "," << smallerValues[p].second << ") ";
		p++;
	}
	std::cout << std::endl;

	return (mainChain);
}


std::vector<int> PmergeMe::jacobsthalOrder(int sizeSmallerValues)
{
	std::vector<int>order;
	std::vector<int>temp;	//holds index

	temp.push_back(0);
	temp.push_back(1);

	int	sizeTemp;
	int	next;

	sizeTemp = temp.size();

	while(sizeTemp - 1 < sizeSmallerValues)
	{
		next = temp[sizeTemp - 1] + 2 * temp[sizeTemp - 2];
		temp.push_back(next);
		sizeTemp = temp.size();
	}

	// debug print: generated Jackobsthal numbers
	int	i;

	i = 0;
	
	while (i < sizeTemp)
	{
		std::cout << temp[i] << " ";
		std::cout << std::endl;
		i++;
	}

	// build insertion of smallerValues with Jackobsthal 
	int	previous;
	int	current;
	int	limit;
	int	insertIndex;
	int	j;

	previous = temp[1];
	j = 2;

	while(previous < sizeSmallerValues && j < sizeTemp)
	{
		current = temp[j];

		if (current < sizeSmallerValues)
			limit = current;
		else
			limit = sizeSmallerValues;
		
		insertIndex = limit;
		while (insertIndex > previous)
		{
			order.push_back(insertIndex);
			insertIndex--;
		}
		previous = current;
		j++;
	}

	return (order);
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
