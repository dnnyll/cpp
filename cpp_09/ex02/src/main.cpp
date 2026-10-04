#include	<iostream>
#include	"../inc/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	#ifdef DEBUG
	std::cout << "[MAIN]\t\tcalled." << std::endl;
	#endif

	if(argc < 2)
	{
		std::cerr << "Error: amount number of arguments." << std::endl;
		return (1);
	}
	
	PmergeMe	pmergeme;
	int	i;

	i = 1;

	while (i < argc)
	{
		if (!pmergeme.parseInput(argv[i]))
		{
			return (1);
		}
		i++;
	}

	pmergeme.sortData();

	return (0);
}
