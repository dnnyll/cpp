/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniefe2 <daniefe2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:05:55 by daniefe2          #+#    #+#             */
/*   Updated: 2026/03/30 08:31:36 by daniefe2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../inc/Array.hpp"

//	constructor
template<typename T>
Array<T>::Array() : _array(0), _size(0)
{
	std::cout << "[Array]\tdefault constructor called" << std::endl;
}

//	copy constructor
template<typename T>
Array<T>::Array(const Array<T> &copy) : _array(0), _size(copy._size)
{
	std::cout << "[Array]\tcopy constructor called" << std::endl;
	if(_size > 0)
	{
		_array = new T[_size];
		int	i = 0;
		while (_size > i)
		{
			_array[i] = copy._array[i];
			i++;
		}
	}
}

//	copy assignment operator
template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& source)
{
	std::cout << "[Array]\tcopy assignment operator called" << std::endl;
	if (this != &source)
	{
		delete[] _array;

		_size = source._size;
		if (_size > 0)
		{
			_array = new T[_size];
			int	i = 0;
			while (_size > i)
			{
				_array[i] = source._array[i];
				i++;
			}
		}
		else
			_array = NULL;
	}
	return *this;
}

//	destructor
template<typename T>
Array<T>::~Array()
{
	std::cout << "[Array]\tdestructor called" << std::endl;
	delete[]	_array;
}

template<typename T>
T*	Array<T>::getArray()
{
	return _array;
}