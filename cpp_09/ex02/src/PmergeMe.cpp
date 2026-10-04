#include <string>
#include <iostream>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include "../inc/PmergeMe.hpp"

// Default constructor. Creates an empty PmergeMe and resets both timings,
// so they are never read while still indeterminate.
PmergeMe::PmergeMe()
{
	_timeVector = 0.0;
	_timeDeque = 0.0;
}

// Copy constructor. Leaves the copying itself entirely to the assignment
// operator, which already guards against self-assignment.
PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

// Assignment operator. Copies both containers and both recorded timings,
// doing nothing when an object is assigned to itself.
PmergeMe	&PmergeMe::operator=(const PmergeMe &input)
{
	if (this != &input)
	{
		_data = input._data;
		_algoData = input._algoData;
		_timeVector = input._timeVector;
		_timeDeque = input._timeDeque;
	}
	return (*this);
}

// Destructor. Releases the two containers owned by this instance.
PmergeMe::~PmergeMe()
{
}

// Searches the already parsed values for a duplicate of the given input.
// Returns true and reports an error when the value is already present.
bool	PmergeMe::getDuplicate(const int input)
{
	std::vector<int>::iterator it = _data.begin();

	while (it != _data.end())
	{
		if (*it == input)
		{
			std::cerr << "Error" << std::endl;
			return (true);
		}
		++it;
	}
	return (false);
}

// Converts one command line argument into a positive integer and appends it
// to _data. Rejects anything non numeric, out of int range or duplicated.
bool	PmergeMe::parseInput(const std::string &inputStr)
{
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

	return (true);
}

// Ford-Johnson merge-insert sort for std::vector. Pairs the values, recurses
// on the larger half, front inserts the first small one, then binary inserts
// the remaining small ones following the Jacobsthal order.
std::vector<int>	PmergeMe::sortVector(std::vector<int> inputData)
{
	int		straggler = -1;
	bool	hasStraggler = false;

	if (inputData.size() <= 1)
		return (inputData);

	std::vector<std::pair<int, int> > pairs =
		pairVector(inputData, straggler, hasStraggler);

	std::vector<int> largerValues;

	size_t	i = 0;

	while (i < pairs.size())
	{
		largerValues.push_back(pairs[i].second);
		++i;
	}

	std::vector<int> mainChain = sortVector(largerValues);
	std::vector<std::pair<int, int> > smallerValues;

	i = 0;

	// locate every larger value in the sorted main chain to know its rank
	while (i < pairs.size())
	{
		std::vector<int>::iterator position =
			std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].second);

		int index = position - mainChain.begin();
		smallerValues.push_back(
			std::pair<int, int>(pairs[i].first, index));
		++i;
	}

	size_t	firstSmall = 0;

	// find the small value that belongs at the very front of the chain
	while (firstSmall < smallerValues.size())
	{
		if (smallerValues[firstSmall].second == 0)
			break;
		++firstSmall;
	}

	if (firstSmall < smallerValues.size())
	{
		mainChain.insert(
			mainChain.begin(), smallerValues[firstSmall].first);
		smallerValues.erase(smallerValues.begin() + firstSmall);
	}

	// the chain shifted right by one, so every stored rank is now off by one
	i = 0;

	while (i < smallerValues.size())
	{
		++smallerValues[i].second;
		++i;
	}

	std::vector<int> insertOrder =
		jacobsthalOrder(smallerValues.size());

	i = 0;

	// insert the small values following the Jacobsthal order
	while (i < insertOrder.size())
	{
		int index = insertOrder[i] - 1;
		binaryInsertVector(mainChain, smallerValues[index].first);
		++i;
	}

	// the straggler is inserted last, once all small values are placed
	if (hasStraggler)
		binaryInsertVector(mainChain, straggler);

	return (mainChain);
}

// Same Ford-Johnson merge-insert algorithm, written for std::deque so that
// both containers are sorted independently and can be compared.
std::deque<int>	PmergeMe::sortDeque(std::deque<int> inputData)
{
	int		straggler = -1;
	bool	hasStraggler = false;

	if (inputData.size() <= 1)
		return (inputData);

	std::deque<std::pair<int, int> > pairs =
		pairDeque(inputData, straggler, hasStraggler);

	std::deque<int> largerValues;

	size_t	i = 0;

	while (i < pairs.size())
	{
		largerValues.push_back(pairs[i].second);
		++i;
	}

	std::deque<int> mainChain = sortDeque(largerValues);
	std::deque<std::pair<int, int> > smallerValues;

	i = 0;

	// locate every larger value in the sorted main chain to know its rank
	while (i < pairs.size())
	{
		std::deque<int>::iterator position =
			std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].second);

		int index = position - mainChain.begin();
		smallerValues.push_back(
			std::pair<int, int>(pairs[i].first, index));
		++i;
	}

	size_t	firstSmall = 0;

	// find the small value that belongs at the very front of the chain
	while (firstSmall < smallerValues.size())
	{
		if (smallerValues[firstSmall].second == 0)
			break;
		++firstSmall;
	}

	if (firstSmall < smallerValues.size())
	{
		mainChain.insert(
			mainChain.begin(), smallerValues[firstSmall].first);
		smallerValues.erase(smallerValues.begin() + firstSmall);
	}

	// the chain shifted right by one, so every stored rank is now off by one
	i = 0;

	while (i < smallerValues.size())
	{
		++smallerValues[i].second;
		++i;
	}

	std::vector<int> insertOrder =
		jacobsthalOrder(smallerValues.size());

	i = 0;

	// insert the small values following the Jacobsthal order
	while (i < insertOrder.size())
	{
		int index = insertOrder[i] - 1;
		binaryInsertDeque(mainChain, smallerValues[index].first);
		++i;
	}

	// the straggler is inserted last, once all small values are placed
	if (hasStraggler)
		binaryInsertDeque(mainChain, straggler);

	return (mainChain);
}

// Builds the Jacobsthal insertion order for the given number of small values.
// Returns a permutation of the 1 based slots 1..sizeSmallerValues, in which
// the pending values get binary inserted into the main chain.
// Note: the order is kept because it is the canonical Ford-Johnson step, not
// because it pays off here. binaryInsertVector searches the whole chain, so the
// comparison count stays Theta(n log n) whatever the order, and total element
// moves equal a constant plus the number of inversions in the order.
std::vector<int>	PmergeMe::jacobsthalOrder(int sizeSmallerValues)
{
	std::vector<int>	order;
	std::vector<int>	jacobsthal;

	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	// generate the Jacobsthal numbers until they cover the small values
	while (jacobsthal.back() < sizeSmallerValues)
	{
		int next = jacobsthal.back()
			+ 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}

	int		previous = jacobsthal[0];
	size_t	i = 1;

	// walk the numbers backwards inside each block to get the order
	while (i < jacobsthal.size())
	{
		int	current = jacobsthal[i];
		int	limit = std::min(current, sizeSmallerValues);
		int	index = limit;

		while (index > previous)
		{
			order.push_back(index);
			--index;
		}

		previous = current;

		if (previous >= sizeSmallerValues)
			break ;

		++i;
	}

	return (order);
}

// Inserts a value in a sorted vector at the spot found by binary search,
// so the vector stays sorted in ascending order.
void	PmergeMe::binaryInsertVector(std::vector<int> &chain, int value)
{
	size_t	low = 0;
	size_t	high = chain.size();

	while (low < high)
	{
		size_t mid = (low + high) / 2;

		if (chain[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	chain.insert(chain.begin() + low, value);
}

// Inserts a value in a sorted deque at the spot found by binary search,
// so the deque stays sorted in ascending order.
void	PmergeMe::binaryInsertDeque(std::deque<int> &chain, int value)
{
	size_t	low = 0;
	size_t	high = chain.size();

	while (low < high)
	{
		size_t mid = (low + high) / 2;

		if (chain[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	chain.insert(chain.begin() + low, value);
}

// Sorts the input twice, once with the vector and once with the deque, timing
// each run. Prints the unsorted input, both sorted results and both times.
void PmergeMe::sortData()
{
	clock_t	start;
	clock_t	end;
	size_t	i = 0;

	// print the unsorted sequence
	std::cout << "Before:\t\t";

	while (i < _data.size())
	{
		std::cout << _data[i] << " ";
		++i;
	}

	std::cout << std::endl;

	start = clock();

	_algoData.assign(_data.begin(), _data.end());

	_algoData = sortDeque(_algoData);

	end = clock();

	_timeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	start = clock();
	_data = sortVector(_data);
	end = clock();

	_timeVector = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After (vector):\t";
	i = 0;

	while (i < _data.size())
	{
		std::cout << _data[i] << " ";
		++i;
	}

	std::cout << std::endl;

	std::cout << "After (deque):\t";
	i = 0;

	while (i < _algoData.size())
	{
		std::cout << _algoData[i] << " ";
		++i;
	}

	std::cout << std::endl;

	// print both elapsed times
	std::cout << "Time to process a range of "
		<< _data.size()
		<< " elements with std::vector<int>:\t"
		<< _timeVector << " us" << std::endl;

	std::cout << "Time to process a range of "
		<< _algoData.size()
		<< " elements with std::deque<int>:\t"
		<< _timeDeque << " us" << std::endl;
}

// Splits the input into (smaller, larger) pairs. A trailing value left over by
// an odd length is reported through straggler and hasStraggler.
std::vector<std::pair<int, int> >	PmergeMe::pairVector(
	const std::vector<int> &input,
	int &straggler,
	bool &hasStraggler)
{
	std::vector<std::pair<int, int> > pairs;

	size_t i = 0;

	//	create pairs in ascending order: the swap is what lets the caller treat
	//	.first as the smaller and .second as the larger of the two
	while (i + 1 < input.size())
	{
		int	a = input[i];
		int	b = input[i + 1];

		if (a < b)
			pairs.push_back(std::pair<int, int>(a, b));
		else
			pairs.push_back(std::pair<int, int>(b, a));

		i += 2;
	}

	if (input.size() % 2 == 1)
	{
		straggler = input.back();
		hasStraggler = true;
	}
	else
	{
		hasStraggler = false;
	}

	return (pairs);
}

// Same pairing step as pairVector, written for std::deque. A trailing value
// left over by an odd length is reported through straggler and hasStraggler.
std::deque<std::pair<int, int> > PmergeMe::pairDeque(
	const std::deque<int> &input,
	int &straggler,
	bool &hasStraggler)
{
	std::deque<std::pair<int, int> > pairs;

	size_t i = 0;

	//	create pairs in ascending order: the swap is what lets the caller treat
	//	.first as the smaller and .second as the larger of the two
	while (i + 1 < input.size())
	{
		int a = input[i];
		int b = input[i + 1];

		if (a < b)
			pairs.push_back(std::pair<int, int>(a, b));
		else
			pairs.push_back(std::pair<int, int>(b, a));

		i += 2;
	}

	if (input.size() % 2 == 1)
	{
		straggler = input.back();
		hasStraggler = true;
	}
	else
	{
		hasStraggler = false;
	}

	return (pairs);
}
