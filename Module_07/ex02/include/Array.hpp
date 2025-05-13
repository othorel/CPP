/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:33:46 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/13 14:36:09 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>
# include <cstdlib>

template <typename T>

class Array {

	public:

		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		T& operator[](size_t index);
		const T& operator[](size_t index) const;
		size_t size() const;

	private:

		T* _array;
		size_t _size;

		class outOfRange : public std::exception {
			
			public:

				const char* what() const throw();
		};	
};

# include "Array.tpp"

#endif