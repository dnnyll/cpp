#ifndef		MUTANTSTACK_HPP
#define		MUTANTSTACK_HPP

#include	<stack>
#include	<iostream>

//	inheriting from stack allows us to access the protected variable c
//	which can be found in stl_stack.h (line 146)
//	it also allows to inherit from all functions it contains

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:

		//	type definitions
		typedef typename	std::stack<T>::container_type::iterator iterator;
		typedef typename	std::stack<T>::container_type::const_iterator const_iterator;

		//	OCF
		MutantStack();
		MutantStack(const MutantStack &copy);
		MutantStack	&operator=(const MutantStack &copy);
		~MutantStack();

		//	iterators
		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

//	OCF
//	default constructor
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "[MutantStack]\tdefault constructor called" << std::endl;
}

//	copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) : std::stack<T>(copy)
{
	std::cout << "[MutantStack]\tcopy constructor called" << std::endl;
}

//	copy assignment operator
template <typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &copy)
{
	std::cout << "[MutantStack]\tcopy assignment operator called" << std::endl;
	if (this != &copy)
	{
		std::stack<T>::operator=(copy);
	}
	return (*this);
}

//	destructor
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "[MutantStack]\tdestructor called" << std::endl;
}



//	iterators
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

#endif
