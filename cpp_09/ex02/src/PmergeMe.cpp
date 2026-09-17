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

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &input)
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

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::getDuplicate(const int input)
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

bool PmergeMe::parseInput(const std::string &inputStr)
{
	char *endPtr;
	long inputValue;

	errno = 0;
	inputValue = std::strtol(inputStr.c_str(), &endPtr, 10);

	if (*endPtr != '\0')
	{
		std::cerr << "Error" << std::endl;
		return (false);
	}

	if (errno == ERANGE || inputValue > INT_MAX || inputValue < 0)
	{
		std::cerr << "Error" << std::endl;
		return (false);
	}

	if (getDuplicate(static_cast<int>(inputValue)))
		return (false);

	_data.push_back(static_cast<int>(inputValue));
	return (true);
}

std::vector<int> PmergeMe::sortVector(std::vector<int> inputData)
{
	int straggler = -1;
	bool hasStraggler = false;

	if (inputData.size() <= 1)
		return (inputData);

	std::vector<std::pair<int, int> > pairs =
		pairVector(inputData, straggler, hasStraggler);

	std::vector<int> largerValues;

	for (size_t i = 0; i < pairs.size(); ++i)
		largerValues.push_back(pairs[i].second);

	std::vector<int> mainChain = sortVector(largerValues);
	std::vector<std::pair<int, int> > smallerValues;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		std::vector<int>::iterator position =
			std::find(mainChain.begin(), mainChain.end(), pairs[i].second);

		int index = position - mainChain.begin();
		smallerValues.push_back(
			std::pair<int, int>(pairs[i].first, index));
	}

	size_t firstSmall = 0;

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

	for (size_t i = 0; i < smallerValues.size(); ++i)
		++smallerValues[i].second;

	std::vector<int> insertOrder =
		jacobsthalOrder(smallerValues.size());

	for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		int index = insertOrder[i] - 1;
		binaryInsertVector(mainChain, smallerValues[index].first);
	}

	if (hasStraggler)
		binaryInsertVector(mainChain, straggler);

	return (mainChain);
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> inputData)
{
	int straggler = -1;
	bool hasStraggler = false;

	if (inputData.size() <= 1)
		return (inputData);

	std::deque<std::pair<int, int> > pairs =
		pairDeque(inputData, straggler, hasStraggler);

	std::deque<int> largerValues;

	for (size_t i = 0; i < pairs.size(); ++i)
		largerValues.push_back(pairs[i].second);

	std::deque<int> mainChain = sortDeque(largerValues);
	std::deque<std::pair<int, int> > smallerValues;

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		std::deque<int>::iterator position =
			std::find(mainChain.begin(), mainChain.end(), pairs[i].second);

		int index = position - mainChain.begin();
		smallerValues.push_back(
			std::pair<int, int>(pairs[i].first, index));
	}

	size_t firstSmall = 0;

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

	for (size_t i = 0; i < smallerValues.size(); ++i)
		++smallerValues[i].second;

	std::vector<int> insertOrder =
		jacobsthalOrder(smallerValues.size());

	for (size_t i = 0; i < insertOrder.size(); ++i)
	{
		int index = insertOrder[i] - 1;
		binaryInsertDeque(mainChain, smallerValues[index].first);
	}

	if (hasStraggler)
		binaryInsertDeque(mainChain, straggler);

	return (mainChain);
}

std::vector<int> PmergeMe::jacobsthalOrder(int sizeSmallerValues)
{
	std::vector<int> order;
	std::vector<int> jacobsthal;

	jacobsthal.push_back(0);
	jacobsthal.push_back(1);

	while (jacobsthal.back() < sizeSmallerValues)
	{
		int next = jacobsthal.back()
			+ 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}

	int previous = jacobsthal[0];

	for (size_t i = 1; i < jacobsthal.size(); ++i)
	{
		int current = jacobsthal[i];
		int limit = std::min(current, sizeSmallerValues);

		for (int index = limit; index > previous; --index)
			order.push_back(index);

		previous = current;

		if (previous >= sizeSmallerValues)
			break;
	}

	return (order);
}

void PmergeMe::binaryInsertVector(
	std::vector<int> &chain, int value)
{
	size_t low = 0;
	size_t high = chain.size();

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

void PmergeMe::binaryInsertDeque(
	std::deque<int> &chain, int value)
{
	size_t low = 0;
	size_t high = chain.size();

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

bool PmergeMe::sortData()
{
	clock_t start;
	clock_t end;

	std::cout << "Before: ";
	for (size_t i = 0; i < _data.size(); ++i)
		std::cout << _data[i] << " ";
	std::cout << std::endl;

	_algoData.assign(_data.begin(), _data.end());

	start = clock();
	_data = sortVector(_data);
	end = clock();

	_timeVector = static_cast<double>(end - start)
		/ CLOCKS_PER_SEC * 1000000.0;

	start = clock();
	_algoData = sortDeque(_algoData);
	end = clock();

	_timeDeque = static_cast<double>(end - start)
		/ CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After: ";
	for (size_t i = 0; i < _data.size(); ++i)
		std::cout << _data[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of "
		<< _data.size()
		<< " elements with std::vector<int> : "
		<< _timeVector << " us" << std::endl;

	std::cout << "Time to process a range of "
		<< _algoData.size()
		<< " elements with std::deque<int> : "
		<< _timeDeque << " us" << std::endl;

	return (true);
}

std::vector<std::pair<int, int> > PmergeMe::pairVector(
	const std::vector<int> &input,
	int &straggler,
	bool &hasStraggler)
{
	std::vector<std::pair<int, int> > pairs;

	size_t i = 0;

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

std::deque<std::pair<int, int> > PmergeMe::pairDeque(
	const std::deque<int> &input,
	int &straggler,
	bool &hasStraggler)
{
	std::deque<std::pair<int, int> > pairs;

	size_t i = 0;

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

std::vector<int> PmergeMe::getSortedVector() const
{
	return (_data);
}
