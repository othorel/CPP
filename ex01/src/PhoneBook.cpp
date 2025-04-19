/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:51:22 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/19 12:18:07 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _old(0) {
}

PhoneBook::~PhoneBook() {
}

void	PhoneBook::add_contact(void) {
	Contact contact;
	contact.setContact();

	if (!contact.isValid()) {
		std::cerr << RED << "Contact not added: all fields are required." << RESET << std::endl;
		return ;
	}
	if (_count < 8)
		contacts[_count++] = contact;
	else {
		std::cerr << RED << "PhoneBook is full. Replacing oldest contact." << RESET << std::endl;
		contacts[_old] = contact;
		_old = (_old + 1) % 8;
	}
}

void	PhoneBook::search_contact(void) {
	int	i;
	int	index;

	i = 0;
	index = -1;
	if (_count == 0) {
		std::cerr << RED << "No contacts to display." << RESET << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (i < _count) {
		contacts[i].displaySummary(i + 1);
		++i;
	}
	while (true) {
		std::cout << GREEN << "Enter index to view full contact " RESET;
		if (!(std::cin >> index)) {
			if (std::cin.eof()) {
				std::cout << "\nEOF received. Exiting." << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return ;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << RED << "Invalid input. Please enter a valid number." << RESET << std::endl;
			continue ;
		}
		if (index < 1 || index > _count) {
			std::cerr << RED << "Index out of range. Please enter a number between 1 and " << _count << "." << RESET << std::endl;
			continue ;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break ;
	}
	index -= 1;
	contacts[index].displayFull();
}
