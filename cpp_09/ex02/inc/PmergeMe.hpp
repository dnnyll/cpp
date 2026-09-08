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
		std::deque<int>						sortDeque(std::deque<int> input);
		std::vector<std::pair<int, int> >	pairVector(const std::vector<int> &input, int &straggler, bool &hasStraggler);
		int									binaryInsertVector(std::vector<int> &chain, int value, int upperBound);
		std::vector<int>					jacobsthalOrder(int n);
		
		
		// int		getResult() const;
		// bool	fordJohnson(std::vector<int> input&);
		// bool	buildPair(int, int?);
		// bool	binaryInsetion(?);

		// std::vector	getResult() const;
		// double	timer();
};

#endif



// ┌───────────────────────────────────────────────────────────────┐
// │ FORD-JOHNSON (vector) — PLAN                                     │
// ├───────────────────────────────────────────────────────────────┤
// │ 1. ENTRY FUNCTION                                                 │
// │    sortVector(std::vector<int> data) -> std::vector<int>          │
// │    - base case: if data.size() <= 1, return data as-is            │
// ├───────────────────────────────────────────────────────────────┤
// │ 2. PAIRING STEP                                                   │
// │    - walk data two elements at a time                             │
// │    - compare each pair, store as (smaller, larger)                │
// │    - keep association: which "smaller" belongs to which "larger"  │
// │      (e.g. vector<pair<int,int>> pairs, .first=small .second=large)│
// │    - if data.size() is odd -> last unpaired element = straggler   │
// ├───────────────────────────────────────────────────────────────┤
// │ 3. BUILD "LARGER" GROUP                                            │
// │    - extract .second of every pair into its own vector<int>       │
// ├───────────────────────────────────────────────────────────────┤
// │ 4. RECURSE                                                         │
// │    - call sortVector() on the "larger" group                      │
// │    - result = sorted "main chain"                                  │
// ├───────────────────────────────────────────────────────────────┤
// │ 5. REBUILD ASSOCIATIONS AFTER RECURSION                            │
// │    - recursion reorders values, so you need a way to still know   │
// │      which "small" belongs to which now-repositioned "large"      │
// │    - options: use pair-preserving recursion, or look up by value  │
// │      (careful with duplicates if allowed)                          │
// ├───────────────────────────────────────────────────────────────┤
// │ 6. INSERT FIRST SMALL                                              │
// │    - the small paired with the main chain's first (smallest)      │
// │      large element gets inserted at the front, no search needed   │
// ├───────────────────────────────────────────────────────────────┤
// │ 7. JACOBSTHAL ORDER FOR REMAINING SMALLS                           │
// │    - generate Jacobsthal numbers up to needed count                │
// │    - derive insertion index order from them (descending per group)│
// ├───────────────────────────────────────────────────────────────┤
// │ 8. BINARY INSERTION LOOP                                           │
// │    - for each remaining small, in Jacobsthal order:                │
// │      - binary search within chain, bounded by its large partner's │
// │        current position (upper bound = partner's index)            │
// │      - insert at found position                                    │
// ├───────────────────────────────────────────────────────────────┤
// │ 9. INSERT STRAGGLER (if any)                                       │
// │    - binary search full chain, insert at found position            │
// ├───────────────────────────────────────────────────────────────┤
// │ 10. RETURN                                                          │
// │     - chain is now fully sorted -> return it                        │
// └───────────────────────────────────────────────────────────────┘