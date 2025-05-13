/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:55:37 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/13 15:44:03 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : _array(NULL), _size(0) {
	*this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete [] _array;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
	if (index >= _size)
		throw outOfBounds();
	return (_array[index]);
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
	if (index >= _size)
		throw outOfBounds();
	return (_array[index]);
}

template <typename T>
size_t Array<T>::size() const {
	return (_size);
}

template <typename T>
const char* Array<T>::outOfBounds::what() const throw() {
	return ("Index out of bounds");
}

# include "Array.hpp"

#endif