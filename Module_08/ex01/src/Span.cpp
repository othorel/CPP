/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:37:47 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/14 11:02:56 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(unsigned int N) : _n(N) {}

Span::Span(const Span& other) : _n(other._n), _numbers(other._numbers) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_n = other._n;
		_numbers = other._numbers;
	}
	return (*this);
}

void Span::addNumber(int num) {
	if (_numbers.size() >= _n)
		throw SpanFullException();
	_numbers.push_back(num);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw SpanTooFewElementsException();
	std::vector<int> temp = _numbers;
	std::sort(temp.begin(), temp.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < temp.size(); i++) {
		int span = temp[i] - temp[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw SpanTooFewElementsException();
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return (max - min);
}

const char* Span::SpanFullException::what() const throw() {
	return ("Span is full, cannot add more numbers.");
}

const char* Span::SpanTooFewElementsException::what() const throw() {
	return ("Not enough elements to find a span.");
}
