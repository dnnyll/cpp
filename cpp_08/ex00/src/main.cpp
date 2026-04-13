#include	"../inc/easyfind.hpp"
#include	<iostream>
#include	<vector>
#include	<list>
#include	<deque>
#include	<stdexcept>

//	valuesSIze, sizeof returns value in bytes, so 5 elements in the arrray
//	corresponds to 5 * 4 = 20. 
//	dividing by sizeof(values[0]) allows us to get the variable size in bytes of the elements
//	contained in the array and it divides it by the same value so we get the number of elements.
//	5 elements * 4 bytes per element (int) = 20bytes; 20bytes / sizeof element[0] bytes (4bytes int)
//	equals 5

int	main(void)
{
	int	values[] = {7, 44, 991, 101, 11};
	int	valuesSize = sizeof(values) / sizeof(values[0]);
	std::vector<int> vect(values, values + valuesSize);
	std::list<int> ls(values, values + valuesSize);
	const std::list<int> constTest(values, values + valuesSize);

	// double	valuesDouble[] = {0.7, 4.4, 99.1, 1.01, 1.1};
	// valuesSize = sizeof(valuesDouble) / sizeof(valuesDouble[0]);
	// std::deque<double> deq(valuesDouble, valuesDouble + valuesSize);

	try
	{
		//	valid tests
		std::cout << "testing number: 991" << std::endl;
		std::vector<int>::iterator testVector = easyfind(vect, 991);
		std::cout << *testVector << "\tfound in vector\n" << std::endl;

		std::cout << "testing number: 11" << std::endl;
		std::list<int>::iterator testList = easyfind(ls, 11);
		std::cout << *testList << "\tfound in list\n" << std::endl;

		std::cout << "testing const number: 7" << std::endl;
		std::list<int>::const_iterator testConstTestList = easyfind(constTest, 7);
		std::cout << *testConstTestList << "\tfound in list\n" << std::endl;

		// std::cout << "testing number: 1.01" << std::endl;
		// std::deque<double>::iterator testDeque = easyfind(deq, 4.4);
		// std::cout << *testDeque << "\tfound in deque\n" << std::endl;

		//	invalid test
		std::cout << "testing number: 0" << std::endl;
		std::vector<int>::iterator testWrong = easyfind(vect, 0);
		std::cout << *testWrong << "\tfound in list" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "error:\t" << e.what() << '\n';
	}

	return (0);
}