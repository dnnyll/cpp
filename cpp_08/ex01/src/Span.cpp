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

int	Span::shortestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("error: Span contains less than 2 elements");

	std::vector<int> copy = this->_numbers;
	std::sort(copy.begin(), copy.end());

	int		minSpan = copy[1] - copy[0];
	size_t	i = 1;

	while (i < copy.size() - 1)
	{
		int	currentSpan = copy[i + 1] - copy[i];
		
		if (currentSpan < minSpan)
			minSpan = currentSpan;
		++i;
	}
	return (minSpan);
}

int	Span::longestSpan()
{
	if (this->_numbers.size() < 2)
		throw std::runtime_error("error: Span contains less than 2 elements");

	std::vector<int> copy = this->_numbers;

	int	minVal = copy[0];
	int	maxVal = copy[0];

	size_t	i = 1;
	while (i < copy.size())
	{
		if (copy[i] < minVal)
			minVal = copy[i];

		if (copy[i] > maxVal)
			maxVal = copy[i];
		++i;
	}

	int	maxSpan = maxVal - minVal;

	return (maxSpan);
}
