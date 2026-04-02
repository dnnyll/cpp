#include	"../inc/Span.hpp"
#include	<iostream>
#include <algorithm>

//	OCF
//	default constructor
Span::Span(unsigned int _N)
{
	std::cout << "[Span]\tdefault constructor called" << std::endl;
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
		type = copy.type;
	return (*this);
}

//	destructor
Span::~Span()
{
	std::cout << "[Span]\tdestructor called" << std::endl;
}

//	methods
void	Span::addNumber(int value)
{
	if (this->_numbers.size() > _N)
		throw std::runtime_error("size overflow");
	this->_numbers.push_back(number);
	isSorted = false;
}

int	Span::shorttestSpan()
{
	if (this->values.size() < 2)
		throw std::runtime_error("error: Span contains less than 2 elements");
	std::vector<int> values;
	std::vector<int> copy = values;
	std::sort(copy.begin(), copy.end());
	
}

int	Span::longestestSpan()
{
	if (this->values.size() < 2)
		throw std::runtime_error("error: Span contains less than 2 elements");
}