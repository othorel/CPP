/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:36:03 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/19 11:02:40 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isPositiveInt(const std::string& str) {
	if (str.empty())
		return (false);
	for (std::string::size_type i = 0; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return (false);
	}
	std::istringstream iss(str);
	long nb;
	iss >> nb;
	return (nb > 0 && nb <= INT_MAX);
}

void printSequence(const std::vector<int>& vec,const std::string& prefix) {
	std::cout << prefix;
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;
}

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: bad arguments." << std::endl;
		return (1);
	}
	std::vector<int> vec;
	std::deque<int> deq;
	for (int i = 1; i < ac; i++) {
		std::string arg(av[i]);
		if (!isPositiveInt(arg)) {
			std::cerr << "Error: not positive int." << std::endl;
			return (1);
		}
		int value = std::atoi(av[i]);
		vec.push_back(value);
		deq.push_back(value);
	}
	printSequence(vec, "Before:");
	
	std::clock_t startVec = std::clock();
	PmergeMe::sortVector(vec);
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
	PmergeMe::sortDeque(deq);
	std::clock_t endDeq = std::clock();

	printSequence(vec, "After:");

	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector: " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::deque: " << timeDeq << " us" << std::endl;
	return (0);
}
