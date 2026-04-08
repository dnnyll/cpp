#include	<stack>
#include	<list>
#include	<iostream>
#include	"../inc/MutantStack.hpp"

int	main()
{
	{
		std::cout << "\n_________default main test" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n_________start iteration int test" << std::endl;
		std::cout << "\nsetting stack" << std::endl;
		MutantStack<int> stackA;
		std::cout << "_________" << std::endl;
		stackA.push(4);
		std::cout << stackA.top() << std::endl;
		stackA.push(7);
		std::cout << stackA.top() << std::endl;
		stackA.push(888);
		std::cout << stackA.top() << std::endl;
		stackA.push(101);
		std::cout << stackA.top() << std::endl;
		stackA.push(666);
		std::cout << stackA.top() << std::endl;
		stackA.push(55);
		std::cout << stackA.top() << std::endl;
		std::cout << "_________" << std::endl;
		std::cout << "end set stack" << std::endl;
		std::cout << "stack size: " << stackA.size() << std::endl;
		std::cout << "\nremoving top element" << std::endl;
		stackA.pop();
		std::cout << "stack size: " << stackA.size() << std::endl;
		std::cout << "printing top element" << std::endl;
		std::cout << stackA.top() << std::endl;
		std::cout << "\nsetting begin and end iterators" << std::endl;
		MutantStack<int>::iterator it = stackA.begin();
		MutantStack<int>::iterator ite = stackA.end();
		std::cout << "iterating x2 ++" << std::endl;
		++it;
		++it;
		std::cout << "_________" << std::endl;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::cout << "_________" << std::endl;

		std::cout << "iterating x1 --" << std::endl;
		--it;
		std::cout << "_________" << std::endl;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::cout << "_________" << std::endl;
	}
	{
		std::cout << "\n_________copy test" << std::endl;
		
		MutantStack<int>	originalStack;
		originalStack.push(1);
		std::cout << originalStack.top() << std::endl;
		originalStack.push(2);
		std::cout << originalStack.top() << std::endl;
		originalStack.push(3);
		std::cout << originalStack.top() << std::endl;

		MutantStack<int>	copyStack = originalStack;

		MutantStack<int>::iterator it = copyStack.begin();
		MutantStack<int>::iterator ite = copyStack.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::cout << "\n_________copy assign test" << std::endl;
		MutantStack<int>	anotherStack;

		anotherStack = originalStack;

		std::cout << "anotherStack after assignment:" << std::endl;
		for (MutantStack<int>::iterator it = anotherStack.begin(); it != anotherStack.end(); ++it)
			std::cout << *it << std::endl;
	}
	{
		std::cout << "\n_________test empty stack" << std::endl;

		MutantStack<int>	*testA = new MutantStack<int>();
		testA->pop();
		testA->top();
	}
	{
		std::cout << "\n_________large stack" << std::endl;

		MutantStack<int>	giantStash;
		for (int i = 0; i < 10000; i++)
			giantStash.push(i);
		std::cout << giantStash.top() << std::endl;
	}
	{
		std::cout << "\n_________vector test" << std::endl;

		std::list<int> ls;
		ls.push_back(7);
		ls.push_back(17);
		ls.pop_back();
		ls.push_back(4);
		ls.push_back(9999);
		ls.push_back(101);
		ls.push_back(0);
		std::list<int>::iterator it = ls.begin();
		std::list<int>::iterator ite = ls.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	return (0);
}
