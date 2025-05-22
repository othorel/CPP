/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:22:21 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/21 14:48:43 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe() {}

//Vector version
void insertionSortVector(std::vector<int>& vec, size_t begin, size_t end) {
	for (size_t i = begin + 1; i < end; i++) {
		int key = vec[i];
		size_t j = i;
		while (j > begin && vec[j - 1] > key) {
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = key;
	}
}

void PmergeMe::sortVector(std::vector<int>& vec) {
	size_t n = vec.size();
	if (n <= 1)
		return;
	for (size_t i = 0; i + 1 < n; i+=2) {
		if (vec[i] > vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
	}
	std::vector<int> sorted;
	for (size_t i = 0; i + 1 < n; i+=2)
		sorted.push_back(vec[i]);
	if (n % 2 != 0)
		sorted.push_back(vec[n - 1]);
	insertionSortVector(sorted, 0, sorted.size());
	for (size_t i = 0; i + 1 < n; i+=2) {
		int value = vec[i + 1];
		std::vector<int>::iterator pos = std::upper_bound(sorted.begin(), sorted.end(), value);
		sorted.insert(pos, value);
	}
	vec = sorted;
}
//Deque version
void insertionSortDeque(std::deque<int>& deq, size_t begin, size_t end) {
	for (size_t i = begin + 1; i < end; i++) {
		int key = deq[i];
		size_t j = i;
		while (j > begin && deq[j - 1] > key) {
			deq[j] = deq[j - 1];
			j--;
		}
		deq[j] = key;
	}
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
	size_t n = deq.size();
	if (n <= 1)
		return;
	for (size_t i = 0; i + 1 < n; i+=2) {
		if (deq[i] > deq[i + 1])
			std::swap(deq[i], deq[i + 1]);
	}
	std::deque<int> sorted;
	for (size_t i = 0; i + 1 < n; i+=2)
		sorted.push_back(deq[i]);
	if (n % 2 != 0)
		sorted.push_back(deq[n - 1]);
	insertionSortDeque(sorted, 0, sorted.size());
	for (size_t i = 0; i + 1 < n; i+=2) {
		int value = deq[i + 1];
		std::deque<int>::iterator pos = std::upper_bound(sorted.begin(), sorted.end(), value);
		sorted.insert(pos, value);
	}
	deq = sorted;
}
