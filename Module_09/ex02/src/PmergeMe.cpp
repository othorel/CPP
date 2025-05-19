/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:22:21 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/19 11:01:27 by olthorel         ###   ########.fr       */
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
		while (j > begin && vec[j + 1] > key) {
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = key;
	}
}

void mergeInsertSortVector(std::vector<int>& vec, size_t begin, size_t end) {
	if (end - begin <= 16) {
		insertionSortVector(vec, begin, end);
		return;
	}
	size_t mid = begin + (end - begin) / 2;
	mergeInsertSortVector(vec, begin, end);
	mergeInsertSortVector(vec, mid, end);
	std::inplace_merge(vec.begin() + begin, vec.begin() + mid, vec.begin() + end);
}

void PmergeMe::sortVector(std::vector<int>& vec) {
	mergeInsertSortVector(vec, 0, vec.size());
}
//Deque version
void insertionSortDeque(std::deque<int>& deq, size_t begin, size_t end) {
	for (size_t i = begin + 1; i < end; i++) {
		int key = deq[i];
		size_t j = i;
		while (j > begin && deq[j + 1] > key) {
			deq[j] = deq[j - 1];
			j--;
		}
		deq[j] = key;
	}
}

void mergeInsertSortDeque(std::deque<int>& deq, size_t begin, size_t end) {
	if (end - begin <= 16) {
		insertionSortDeque(deq, begin, end);
		return;
	}
	size_t mid = begin + (end - begin) / 2;
	mergeInsertSortDeque(deq, begin, end);
	mergeInsertSortDeque(deq, mid, end);
	std::inplace_merge(deq.begin() + begin, deq.begin() + mid, deq.begin() + end);
}

void PmergeMe::sortDeque(std::deque<int>& deq) {
	mergeInsertSortDeque(deq, 0, deq.size());
}
