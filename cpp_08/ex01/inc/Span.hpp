#ifndef		SPAN_HPP
# define	SPAN_HPP

#include	<iostream>
#include	<string>
#include	<vector>

class	Span
{
	private:

		unsigned int		_N;
		unsigned int		_size;
		std::vector<int>	_numbers;

	public:

		Span(unsigned int value);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		~Span();

		void	addNumber(int value);
		shorttestSpan();
		longestestSpan();

}
#endif
