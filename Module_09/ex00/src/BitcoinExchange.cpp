/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:24:53 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/14 15:24:53 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
	parseCSV(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	_rates = other._rates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_rates = other._rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::parseCSV(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr)) {
			std::cerr << "Error: bad line in database => " << line << std::endl;
			continue;
		}
		float value = std::strtof(valueStr.c_str(), NULL);
		_rates[date] = value;
	}
}

float BitcoinExchange::getRateForDate(const std::string& date) const {
	if (_rates.empty()) {
		std::cerr << "Error: database is empty." << std::endl;
		return (-1);
	}
	std::map<std::string, float>::const_iterator it = _rates.lower_bound(date);
	if (it != _rates.end() && it->first == date)
		return (it->second);
	if (it == _rates.begin()) {
		std::cerr << "Error: no earlier data available for => " << date << std::endl;
		return (-1);
	}
	return (it->second);
}
