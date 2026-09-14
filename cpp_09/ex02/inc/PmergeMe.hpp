#ifndef		PMERGEME_HPP
# define	PMERGEME_HPP

#include	<string>
#include	<vector>
#include	<deque>

class	PmergeMe
{

	// variables
	private:
		std::vector<int>					_data;
		std::deque<int>						_algoData;
		std::vector<std::pair<int, int> >	_pairs;

		double								_timeVector;
		double								_timeDeque;

	// methods
	private:
	
	public:
		PmergeMe();											// default constructor
		PmergeMe(const PmergeMe &src);						// copy constructor
		PmergeMe &operator=(const PmergeMe &rhs);			// assignment operator
		~PmergeMe();										// destructor

		bool								parseInput(const std::string &inputStr);
		bool								getDuplicate(const int input);
		bool								sortData();
		std::vector<int>					sortVector(std::vector<int> input);
		std::vector<std::pair<int, int> >	pairVector(const std::vector<int> &input, int &straggler, bool &hasStraggler);
		void								binaryInsertVector(std::vector<int> &chain, int value);
		std::vector<int>					jacobsthalOrder(int n);
		std::vector<int>					getSortedVector() const;
		std::deque<int>						sortDeque(std::deque<int> input);
		std::deque<std::pair<int, int> >	pairDeque(const std::deque<int> &input, int &straggler, bool &hasStraggler);
		void								binaryInsertDeque(std::deque<int> &chain, int value);
		
};

#endif
