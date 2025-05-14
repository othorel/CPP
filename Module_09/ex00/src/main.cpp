/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:44:40 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/14 15:44:40 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return (false);
	}
	return (true);
}

bool isValidValue(const std::string& valueStr, float& value) {
	char* end = NULL;
	value = std::strtof(valueStr.c_str(), &end);
	if (*end != '\0') {
		std::cerr << "Error: not a valid number => " << valueStr << std::endl;
		return (false);
	}
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	BitcoinExchange exchange("data.csv");
	std::ifstream input(av[1]);
	if (!input.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	std::string line;
	std::getline(input, line);
	while (std::getline(input, line)) {
		if (line.empty())
			continue;
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		date.erase(date.find_last_not_of(" \t") + 1);
		date.erase(0, date.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		float value;
		if (!isValidValue(valueStr, value))
			continue;
		float rate = exchange.getRateForDate(date);
		if (rate == -1)
			continue;
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
	return (0);
}
