#include	"../inc/Span.hpp"
#include	<iostream>
#include	<cstdlib>
#include	<sys/time.h>

int	get_time(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	main()
{
	{
		std::cout << "\n_________default main test" << std::endl;

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\n_________add range test" << std::endl;

		int		values[] = {0, 4, 23, 47, 777, -666, -101, 333, -25, -11, 89};
		size_t	size = sizeof(values) / sizeof(values[0]);

		std::vector<int> vect(values, values + size);

		Span	rangeTest(size);
		rangeTest.addNumbers(vect.begin(), vect.end());

		std::cout << rangeTest.shortestSpan() << std::endl;
		std::cout << rangeTest.longestSpan() << std::endl;
	}
	{
		std::cout << "\n_________add range overflow test" << std::endl;

		Span	overflowTest(5);
		std::vector<int> big(10, 42);

		try
		{
			overflowTest.addNumbers(big.begin(), big.end());
		}
		catch (const std::exception &e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}
	{
		try
		{
			#define	N_VALUES	1001

			std::cout << "\n_________random large test" << std::endl;


			Span	giantTest = N_VALUES;
			int		start;
			int		i;

			start = get_time();
			i = 0;
			std::srand(start);
			while (i < N_VALUES)
			{
				giantTest.addNumber(std::rand());
				i++;
			}
			start = get_time();

			std::cout << giantTest.shortestSpan() << std::endl;
			std::cout << giantTest.longestSpan() << std::endl;
		}
		catch (const std::exception& e) 
		{
			std::cerr << "error:\t" << e.what() << '\n';
		}
	}
	return (0);
}