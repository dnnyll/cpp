#ifndef		SPAN_HPP
# define	SPAN_HPP

#include	<iostream>
#include	<vector>
#include	<stdexcept>

class	Span
{
private:
	unsigned int		_N;
	std::vector<int>	_numbers;

public:
	Span(unsigned int N);
	Span(const Span& copy);
	Span& operator=(const Span& copy);
	~Span();

	void	addNumber(int value);

	template <typename Iterator>
	void	addNumbers(Iterator begin, Iterator end);

	int	shortestSpan();
	int	longestSpan();

};

//	std::distance calcul num of iter between input elements
template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	size_t	distance = std::distance(begin, end);

	if (this->_numbers.size() + distance > this->_N)
		throw std::runtime_error("size overflow");

	this->_numbers.insert(this->_numbers.end(), begin, end);
}

#endif
