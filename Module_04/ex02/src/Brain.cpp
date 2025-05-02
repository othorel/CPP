/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:07:18 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/01 18:07:18 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	const std::string tab[] = {
		"I want water",
		"I want food",
		"I want to sleep",
		"I want run",
		"I want pets",
		"I want attention",
		"I want to fetch the ball",
		"I want to look out the window",
		"I want to watch TV",
		"I want to go to the park",
	};
	for (int i = 0; i < 100; i++)
	this->_ideas[i] = tab[rand() % 10];
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	std::cout << "Brain copie constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

const std::string& Brain::getIdea(int index) const {
	return (_ideas[index]);
}

void Brain::setIdea(int index, const std::string& ideas) {
	if (index >= 0 && index < 100)
		_ideas[index] = ideas;
}
