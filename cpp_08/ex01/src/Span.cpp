#include	"../inc/Span.hpp"
#include	<iostream>
#include	<algorithm>
#include	<limits>

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
Span	&Span::operator=(const Span &copy)
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

void	Span::addNumber(int value)
{
	if (this->_numbers.size() >= _N)
		throw std::runtime_error("size overflow");

	this->_numbers.push_back(value);
}

/*
	copies our _numbers vector
	sorts it
	computes minimal difference between elements and replaces the value in minSpan
*/
int	Span::shortestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("error: span contains less than 2 elements");

	std::vector<int> copy = this->_numbers;
	std::sort(copy.begin(), copy.end());

	int		minSpan = std::numeric_limits<int>::max();
	size_t	i = 0;

	while (i < copy.size() - 1)
	{
		minSpan = std::min(minSpan, copy[i + 1] - copy[i]);
		++i;
	}
	return (minSpan);
}

/*
	std:min/max_element 
		takes the 2 iterators begin/end
		goes through every element between them
		returns an iterator pointing to the smallest value found
*/
int	Span::longestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("error: span contains less than 2 elements");

	int	minVal = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int	maxVal = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	return (maxVal - minVal);
}


