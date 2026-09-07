#ifndef		PMERGEME_HPP
# define	PMERGEME_HPP

#include	<string>
#include	<vector>
#include	<list>

class	PmergeMe
{

	// variables
	private:
		std::vector<int>					_data;
		// std::list<int>						_algoData;
		// std::vector<std::pair<int, int>>	_pairs;


	// methods
	private:
	
	public:
		PmergeMe();											// default constructor
		PmergeMe(const PmergeMe &src);						// copy constructor
		PmergeMe &operator=(const PmergeMe &rhs);			// assignment operator
		~PmergeMe();										// destructor

		// int		getResult() const;
		bool	parseInput(const std::string &inputStr);
		// convert to int
		// check if isdigit
		// check if it isn't duplicate
		// check if not negative
		// check if overflow

		// bool	sortData(std::vector<int> input);
		// bool	fordJohnson(std::vector<int> input&);
		// bool	buildPair(int, int?);
		// bool	binaryInsetion(?);

		// std::vector	getResult() const;
		// double	timer();
};

#endif
