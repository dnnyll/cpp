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
			std::cerr << "Error: wrong input." << std::endl;
			return (1);
		}
		i++;
	}

	if(!pmergeme.sortData())
	{
		std::cerr << "Error: sorting anomaly found." << std::endl;
		return (1);
	}
	
	return (0);
}