/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:37:47 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/13 17:48:26 by olthorel         ###   ########.fr       */
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
}