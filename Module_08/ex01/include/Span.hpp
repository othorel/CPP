/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:23:58 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/13 17:38:54 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>

class Span {
	
	public:

		Span();
		Span(unsigned int N);
		Span(const Span& other);
		~Span();
		Span& operator=(const Span& other);

		void addNumber(int num);

		template <typename T>
		void addNumbersRange(T begin, T end);

		int shortestSpan() const;
		int longestSpan() const;

	private:

		unsigned int _n;
		std::vector<int> _numbers;

		class SpanFullException : public std::exception {

			public:

				const char* what() const throw();
		};
		class SpanTooFewElementsException : public std::exception {
			
			public:

				const char* what() const throw();
		};
};

#endif