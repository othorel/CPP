/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:24:12 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/14 11:24:12 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>
# include <iostream>
# include <list>

template <typename T>

class MutantStack : public std::stack<T> {

	public:

		MutantStack();
		MutantStack(const MutantStack<T>& other);
		~MutantStack();
		MutantStack& operator=(const MutantStack<T>& other);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

# include "MutantStack.tpp"

#endif