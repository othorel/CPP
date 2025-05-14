/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:24:44 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/14 10:51:47 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	
	std::cout << "=== BASIC TEST ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "=== RANGE INSERTION TEST (VECTOR) ===" << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(100);
		vec.push_back(200);
		vec.push_back(300);
		vec.push_back(400);
		
		Span sp(10);
		sp.addNumbersRange(vec.begin(), vec.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "=== RANGE INSERTION TEST (LIST) ===" << std::endl;
	{
		std::list<int> lst;
		lst.push_back(-1);
		lst.push_back(-50);
		lst.push_back(0);
		lst.push_back(15);
		
		Span sp(10);
		sp.addNumbersRange(lst.begin(), lst.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << "=== EXCEPTION TEST: SPAN FULL ===" << std::endl;
	{
		try {
			Span sp(2);
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << "=== EXCEPTION TEST: TOO FEW ELEMENTS ===" << std::endl;
	{
		try {
			Span sp(10);
			sp.addNumber(5);
			std::cout << sp.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << "=== LARGE TEST: 10 000 RANDOM NUMBERS ===" << std::endl;
	{
		Span sp(10000);
		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; i++)
			sp.addNumber(std::rand());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return (0);
}
