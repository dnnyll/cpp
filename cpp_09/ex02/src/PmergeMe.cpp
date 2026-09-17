#include	<string>
#include	<iostream>
#include	<cstdlib>
#include	<cerrno>
#include	<climits>
#include	<vector>
#include	<deque>
#include	<algorithm>
#include	<ctime>
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
	#ifdef DEBUG
	std::cout << "[GET DUPLICATE]\tcalled." << std::endl;
	#endif

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
	#ifdef DEBUG
	std::cout << "[PARSE INPUT]\tcalled." << std::endl;
	#endif

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

// recursion vector
std::vector<int>	PmergeMe::sortVector(std::vector<int> inputData)
{
	#ifdef DEBUG
	std::cout << "[SORT VECTOR]\tcalled." << std::endl;
	#endif

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

	// insert remaining smalls in Jacobsthal order
	size_t	m;
	int		idx;
	int		value;

	m = 0;
	while (m < insertOrder.size())
	{
		idx = insertOrder[m];
		value = smallerValues[idx - 1].first;
		binaryInsertVector(mainChain, value);
		m++;
	}

	// straggler inserted last, after all smalls are placed
	if (hasStraggler)
		binaryInsertVector(mainChain, straggler);

	return (mainChain);
}

// recursion deque
std::deque<int>	PmergeMe::sortDeque(std::deque<int> inputData)
{
	#ifdef DEBUG
	std::cout << "[SORT DEQUE]\tcalled." << std::endl;
	#endif

	int		straggler;
	bool	hasStraggler;
	size_t	i;

	straggler = -1;
	hasStraggler = false;
	i = 0;

	if (inputData.size() <= 1)
		return (inputData);

	std::deque<std::pair<int, int> > pairs = pairDeque(inputData, straggler, hasStraggler);

	//	print debug
	while (i < pairs.size())
	{
		std::cout << "pair: (" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;

		if (hasStraggler)
				std::cout << "straggler: " << straggler << std::endl;

		i++;
	}

	// find and gather largerValues
	std::deque<int>	largerValues;

	i = 0;

	while (i < pairs.size())
	{
		largerValues.push_back(pairs[i].second);
		i++;
	}

	// this is the sorted deque of large values, then we need to insert smaller values in it
	std::deque<int> mainChain = sortDeque(largerValues);

	// find and gather smallerValues
	std::deque<std::pair<int, int> > smallerValues;

	i = 0;

	while (i < pairs.size())
	{
		std::deque<int>::iterator position = std::find(mainChain.begin(), mainChain.end(), pairs[i].second);

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

	// insert remaining smalls in Jacobsthal order
	size_t	m;
	int		idx;
	int		value;

	m = 0;
	while (m < insertOrder.size())
	{
		idx = insertOrder[m];
		value = smallerValues[idx - 1].first;
		binaryInsertDeque(mainChain, value);
		m++;
	}

	// straggler inserted last, after all smalls are placed
	if (hasStraggler)
		binaryInsertDeque(mainChain, straggler);

	return (mainChain);
}

std::vector<int> PmergeMe::jacobsthalOrder(int sizeSmallerValues)
{
	#ifdef DEBUG
	std::cout << "[JACOBSTHAL ORDER]\tcalled." << std::endl;
	#endif

	std::vector<int>order;
	std::vector<int>temp;

	temp.push_back(0);
	temp.push_back(1);

	int	next;

	while (temp[temp.size() - 1] < sizeSmallerValues)
	{
		next = temp[temp.size() - 1] + 2 * temp[temp.size() - 2];
		temp.push_back(next);
	}

	// debug print: generated Jacobsthal numbers
	size_t	i;

	i = 0;
	while (i < temp.size())
	{
		std::cout << temp[i] << " ";
		std::cout << std::endl;
		i++;
	}

	// build insertion order using Jacobsthal numbers as block boundaries
	int		previous;
	int		current;
	int		limit;
	int		insertIndex;
	size_t	j;

	previous = temp[0];
	j = 1;

	while (previous < sizeSmallerValues && j < temp.size())
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

void	PmergeMe::binaryInsertVector(std::vector<int> &chain, int value)
{
	#ifdef DEBUG
	std::cout << "[BINARY INSERT VECTOR]\tcalled." << std::endl;
	#endif

	size_t	low;
	size_t	high;
	size_t	mid;

	low = 0;
	high = chain.size();

	while(low < high)
	{
		mid = (low + high) / 2;

		if (chain[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	chain.insert(chain.begin() + low, value);
}

void	PmergeMe::binaryInsertDeque(std::deque<int> &chain, int value)
{
	#ifdef DEBUG
	std::cout << "[BINARY INSERT DEQUE]\tcalled." << std::endl;
	#endif

	size_t	low;
	size_t	high;
	size_t	mid;

	low = 0;
	high = chain.size();

	while(low < high)
	{
		mid = (low + high) / 2;

		if (chain[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	chain.insert(chain.begin() + low, value);
}

bool	PmergeMe::sortData()
{
	#ifdef DEBUG
	std::cout << "[SORT DATA]\tcalled." << std::endl;
	#endif

	clock_t	start;
	clock_t	end;

	size_t	i;
	i = 0;
	
	// print unsorted sequence
	std::cout << "Before: ";

	while (i < _data.size())
	{
		std::cout << _data[i] << " ";
		i++;
	}
	std::cout << std::endl;

	// populate deque from vector data before sorting
	_algoData.assign(_data.begin(), _data.end());

	// time vector sort
	start = clock();
	_data = sortVector(_data);
	end = clock();

	// convert to microseconds
	_timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	// time deque sort
	start = clock();
	_algoData = sortDeque(_algoData);
	end = clock();
	
	// convert to microseconds
	_timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	// print sorted sequence
	std::cout << "After: ";
	i = 0;
	while (i < _data.size())
	{
		std::cout << _data[i] << " ";
		i++;
	}
	std::cout << std::endl;

	// print timing lines
	std::cout << "Time to process a range of " << _data.size()
				<< " elements with std::vector<int> : " << _timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _algoData.size()
				 << " elements with std::deque<int> : " << _timeDeque << " us" << std::endl;

	return (true);
}

std::vector<std::pair<int, int> >	PmergeMe::pairVector(const std::vector<int> &input, int &straggler, bool &hasStraggler)
{
	#ifdef DEBUG
	std::cout << "[PAIR VECTOR]\tcalled." << std::endl;
	#endif

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

std::deque<std::pair<int, int> >	PmergeMe::pairDeque(const std::deque<int> &input, int &straggler, bool &hasStraggler)
{
	#ifdef DEBUG
	std::cout << "[PAIR DEQUE]\tcalled." << std::endl;
	#endif

	std::deque<std::pair<int, int> >	pairs;
	
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

std::vector<int> PmergeMe::getSortedVector() const
{
	#ifdef DEBUG
	std::cout << "[GET SORTED VECTOR]\tcalled." << std::endl;
	#endif

	return (_data);
}
