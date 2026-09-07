#include	<iostream>
#include	"../inc/PmergeMe.hpp"

int	main(int argc, char **argv)
{
	#ifdef DEBUG
	std::cout << "[MAIN]\t\tcalled." << std::endl;
	#endif

	int	i;

	if(argc < 2)
	{
		std::cerr << "Error: amount number of arguments." << std::endl;
		return (1);
	}
	
	PmergeMe	pmergeme;
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
	return (0);
}