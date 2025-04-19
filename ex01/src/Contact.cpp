/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:39:34 by olthorel          #+#    #+#             */
/*   Updated: 2025/04/16 16:39:34 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void	Contact::setContact() {
	std::cout << "First name: ";
	std::getline(std::cin, FirstName);
	std::cout << "Last name: ";
	std::getline(std::cin, LastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, NickName);
	std::cout << "Phone number: ";
	std::getline(std::cin, PhoneNumber);
	while (!isPhoneNumberValid(PhoneNumber)) {
		std::cerr << RED << "Phone number must contain digits only." << RESET << std::endl;
		std::cout << "Phone number: ";
		std::getline(std::cin, PhoneNumber);
	}
	std::cout << "Darkest secret: ";
	std::getline(std::cin, DarkestSecret);
}

bool	Contact::isPhoneNumberValid(const std::string& number) const {
	for (size_t i = 0; i < number.length(); ++i) {
		if (!std::isdigit(number[i]))
			return (false);
	}
	return (true);
}

bool	Contact::isValid() const {
	if (FirstName.empty()) {
		std::cerr << RED << "First name cannot be empty." << RESET << std::endl;
		return (false);
	}
	if (LastName.empty()) {
		std::cerr << RED << "Last name cannot be empty." << RESET << std::endl;
		return (false);
	}
	if (NickName.empty()) {
		std::cerr << RED << "Nick name cannot be empty." << RESET << std::endl;
		return (false);
	}
	if (PhoneNumber.empty()) {
		std::cerr << RED << "Phone number cannot be empty." << RESET << std::endl;
		return (false);
	}
	if (DarkestSecret.empty()) {
		std::cerr << RED << "Dark secret cannot be empty." << RESET << std::endl;
		return (false);
	}
	return (true);
}

std::string	Contact::formatField(const std::string& str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}

void	Contact::displaySummary(int index) const {
	std::string FormattedFirst = formatField(FirstName);
	std::string FormattedLast = formatField(LastName);
	std::string FormattedNick = formatField(NickName);

	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << FormattedFirst << "|";
	std::cout << std::setw(10) << FormattedLast << "|";
	std::cout << std::setw(10) << FormattedNick << std::endl;
}

void	Contact::displayFull() const {
	std::cout << "First name: "     << FirstName << std::endl;
	std::cout << "Last name: "      << LastName  << std::endl;
	std::cout << "Nickname: "       << NickName  << std::endl;
	std::cout << "Phone number: "   << PhoneNumber << std::endl;
	std::cout << "Darkest secret: " << DarkestSecret << std::endl;
}
