#include	"../inc/Span.hpp"
#include	<iostream>
#include	<algorithm>


Span::Span(unsigned int _N) : _N(_N)
{
	std::cout << "[Span]\tconstructor called" << std::endl;
}

//	copy constructor
Span::Span(const Span &copy)
{
	std::cout << "[Span]\tcopy constructor called" << std::endl;
	*this = copy;
}

//	copy assignment operator
Span &Span::operator=(const Span &copy)
{
	std::cout << "[Span]\tcopy assignment operator called" << std::endl;

	if (this != &copy)
	{
		this->_N = copy._N;
		this->_numbers = copy._numbers;
	}
	return (*this);
}

//	destructor
Span::~Span()
{
	std::cout << "[Span]\tdestructor called" << std::endl;
}

void Span::addNumber(int value)
{
	if (this->_numbers.size() >= _N)
		throw std::runtime_error("size overflow");

	this->_numbers.push_back(value);
}

int Span::shortestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("error: Span contains less than 2 elements");

	std::vector<int> copy = this->_numbers;

	//	debug unsorted values
	std::cout << "unsorted values: ";
	for (size_t i = 0; i < copy.size(); ++i)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	std::sort(copy.begin(), copy.end());

	//	debug sorted values
	std::cout << "sorted values:   ";
	for (size_t i = 0; i < copy.size(); ++i)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	int minSpan = copy[1] - copy[0];
	std::cout << "initial minSpan: " << minSpan << std::endl;

	size_t	i = 1;

	while (i < copy.size())
	{
		int diff = copy[i] - copy[i - 1];

		//	debug comparison
		std::cout << "comparing: " << copy[i - 1]
				<< " and " << copy[i]
				<< " -> diff = " << diff << std::endl;

		if (diff < minSpan)
		{
			std::cout << "new minSpan found: " << diff << std::endl;
			minSpan = diff;
		}
		++i;
	}

	std::cout << "final result shortest span: " << minSpan << std::endl;

	return (minSpan);
}

int Span::longestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("error: Span contains less than 2 elements");

	std::vector<int> copy = this->_numbers;

	// debug unsorted values
	std::cout << "values: ";
	for (size_t i = 0; i < copy.size(); ++i)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	int minVal = copy[0];
	int maxVal = copy[0];

	size_t i = 1;
	while (i < copy.size())
	{
		std::cout << "checking: " << copy[i] << std::endl;

		if (copy[i] < minVal)
		{
			minVal = copy[i];
			std::cout << "new min found: " << minVal << std::endl;
		}

		if (copy[i] > maxVal)
		{
			maxVal = copy[i];
			std::cout << "new max found: " << maxVal << std::endl;
		}

		++i;
	}

	int span = maxVal - minVal;

	std::cout << "final result longest span: " << span
			<< " (max: " << maxVal
			<< ", min: " << minVal << ")" << std::endl;

	return (span);
}