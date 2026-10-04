// Debug-traced implementation of PmergeMe. NOT part of the build.
//
// The whole file is wrapped in PMERGEME_DEBUG_BUILD so that adding it to SRCS
// by mistake can never break the link with a duplicate-symbol error: without
// the macro this file compiles to an empty translation unit.
//
// To build it, compile it INSTEAD OF src/PmergeMe.cpp:
//   make fclean
//   make DEBUG=1 SRCS="main.cpp PmergeMeDebug.cpp"
#ifdef PMERGEME_DEBUG_BUILD

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

	_timeVector = 0.0;
	_timeDeque = 0.0;
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
	{
		_data = input._data;
		_algoData = input._algoData;
		_timeVector = input._timeVector;
		_timeDeque = input._timeDeque;
	}
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
			std::cerr << "Error" << std::endl;
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
	inputValue = std::strtol(inputStr.c_str(), &endPtr, 10);

	if (*endPtr != '\0')
	{
		std::cerr << "Error" << std::endl;
		return (false);
	}

	if (errno == ERANGE || inputValue > INT_MAX || inputValue <= 0)
	{
		std::cerr << "Error" << std::endl;
		return (false);
	}

	if (getDuplicate(static_cast<int>(inputValue)))
		return (false);

	_data.push_back(static_cast<int>(inputValue));

	#ifdef DEBUG
	std::vector<int>::iterator	it;

	it = _data.begin();

	while (it != _data.end())
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	#endif

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
		std::vector<int>::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].second);

		int index;

		index = position - mainChain.begin();

		smallerValues.push_back(std::pair<int, int>(pairs[i].first, index));
		i++;
	}

	// find smaller value to insert in the chain
	size_t	firstSmall;

	firstSmall = 0;

	while (firstSmall < smallerValues.size())
	{
		if (smallerValues[firstSmall].second == 0)
			break;
		++firstSmall;
	}

	if (firstSmall < smallerValues.size())
	{
		mainChain.insert(mainChain.begin(), smallerValues[firstSmall].first);
		smallerValues.erase(smallerValues.begin() + firstSmall);
	}

	// mainChain shifted right by 1 after front insertion,
	// so every stored index in smallerValues is now off by one — correct it
	size_t	k;

	k = 0;

	while (k < smallerValues.size())
	{
		++smallerValues[k].second;
		k++;
	}

	// apply jacobsthalOrder to the remaining smallerValues
	std::vector<int> insertOrder;

	insertOrder = jacobsthalOrder(smallerValues.size());

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
		std::deque<int>::iterator position = std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].second);

		int index;

		index = position - mainChain.begin();

		smallerValues.push_back(std::pair<int, int>(pairs[i].first, index));
		i++;
	}

	// find smaller value to insert in the chain
	size_t	firstSmall;

	firstSmall = 0;

	while (firstSmall < smallerValues.size())
	{
		if (smallerValues[firstSmall].second == 0)
			break;
		++firstSmall;
	}

	if (firstSmall < smallerValues.size())
	{
		mainChain.insert(mainChain.begin(), smallerValues[firstSmall].first);
		smallerValues.erase(smallerValues.begin() + firstSmall);
	}

	// mainChain shifted right by 1 after front insertion,
	// so every stored index in smallerValues is now off by one — correct it
	size_t	k;

	k = 0;

	while (k < smallerValues.size())
	{
		++smallerValues[k].second;
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

	std::vector<int>	order;
	std::vector<int>	jacobsthal;

	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	while (jacobsthal.back() < sizeSmallerValues)
	{
		int	next;

		next = jacobsthal.back()
			+ 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}

	// print debug: generated Jacobsthal numbers
	size_t	i;

	i = 0;

	while (i < jacobsthal.size())
	{
		std::cout << jacobsthal[i] << " ";
		std::cout << std::endl;
		i++;
	}

	// build insertion order using Jacobsthal numbers as block boundaries
	int	previous;

	previous = jacobsthal[0];

	for (size_t j = 1; j < jacobsthal.size(); ++j)
	{
		int	current;
		int	limit;

		current = jacobsthal[j];
		limit = std::min(current, sizeSmallerValues);

		for (int index = limit; index > previous; --index)
			order.push_back(index);

		previous = current;

		if (previous >= sizeSmallerValues)
			break;
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

void	PmergeMe::sortData()
{
	#ifdef DEBUG
	std::cout << "[SORT DATA]\tcalled." << std::endl;
	#endif

	clock_t	start;
	clock_t	end;

	size_t	i;

	i = 0;

	// print unsorted sequence
	std::cout << "Before:\t\t";

	while (i < _data.size())
	{
		std::cout << _data[i] << " ";
		i++;
	}
	std::cout << std::endl;

	// the deque is filled and sorted BEFORE the vector, while _data still holds
	// the original unsorted sequence. Filling it after the vector sort would hand
	// the deque an already-sorted input and make the two timings incomparable.
	// The fill stays inside the deque timer so its data management is counted,
	// matching the by-value copy the vector pays inside sortVector.
	start = clock();

	_algoData.assign(_data.begin(), _data.end());

	_algoData = sortDeque(_algoData);

	end = clock();

	// convert to microseconds
	_timeDeque = static_cast<double>(end - start)
		/ CLOCKS_PER_SEC * 1000000.0;

	start = clock();
	_data = sortVector(_data);
	end = clock();

	// convert to microseconds
	_timeVector = static_cast<double>(end - start)
		/ CLOCKS_PER_SEC * 1000000.0;

	// print sorted sequences
	std::cout << "After (vector):\t";

	i = 0;

	while (i < _data.size())
	{
		std::cout << _data[i] << " ";
		i++;
	}
	std::cout << std::endl;

	std::cout << "After (deque):\t";

	i = 0;

	while (i < _algoData.size())
	{
		std::cout << _algoData[i] << " ";
		i++;
	}
	std::cout << std::endl;

	// print timing lines
	std::cout << "Time to process a range of " << _data.size()
		<< " elements with std::vector<int>:\t"
		<< _timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << _algoData.size()
		<< " elements with std::deque<int>:\t"
		<< _timeDeque << " us" << std::endl;
}

std::vector<std::pair<int, int> >	PmergeMe::pairVector(const std::vector<int> &input, int &straggler, bool &hasStraggler)
{
	#ifdef DEBUG
	std::cout << "[PAIR VECTOR]\tcalled." << std::endl;
	#endif

	std::vector<std::pair<int, int> >	pairs;

	size_t	i;
	int		a;
	int		b;

	i = 0;

	while (i + 1 < input.size())
	{
		a = input[i];
		b = input[i + 1];

		if (a < b)
			pairs.push_back(std::pair<int, int>(a, b));
		else
			pairs.push_back(std::pair<int, int>(b, a));

		i += 2;
	}

	if (input.size() % 2 == 1)
	{
		std::cout << "hasStraggler = true" << std::endl;
		straggler = input.back();
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

	size_t	i;
	int		a;
	int		b;

	i = 0;

	while (i + 1 < input.size())
	{
		a = input[i];
		b = input[i + 1];

		if (a < b)
			pairs.push_back(std::pair<int, int>(a, b));
		else
			pairs.push_back(std::pair<int, int>(b, a));

		i += 2;
	}

	if (input.size() % 2 == 1)
	{
		std::cout << "hasStraggler = true" << std::endl;
		straggler = input.back();
		hasStraggler = true;
	}
	else
	{
		std::cout << "hasStraggler = false" << std::endl;
		hasStraggler = false;
	}
	return (pairs);
}

#endif // PMERGEME_DEBUG_BUILD
