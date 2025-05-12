/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:50:57 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/12 09:37:14 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string& str) {
	return (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

static bool isPseudoLiteral(const std::string& str) {
	return (str == "nan" || str == "+inf" || str == "-inf" ||
			str == "nanf" || str == "+inff" || str == "-inff");
}

void ScalarConverter::convert(const std::string &literal) {
	double value;
	char  c;
	char* endPtr;

	// Check if the string is empty
	if (literal.empty()) {
		std::cerr << "Invalid input: empty string" << std::endl;
		return;
	}
	// Check if it's a single character
	if (isChar(literal)) {
		c = literal[0];
		value = static_cast<double>(c);
	}
	// Check if it's a pseudo-literal (nan, inf, etc.)
	else if (isPseudoLiteral(literal)) {
		if (literal[literal.length() - 1] == 'f')
			value = static_cast<double>(std::strtof(literal.c_str(), NULL));  // Convert to float if it ends with 'f'
		else
			value = std::strtod(literal.c_str(), NULL);  // Convert to double if it doesn't have 'f'
	}
	// Attempt to convert to double
	else {
		endPtr = NULL;
		// Remove the 'f' from the string if present (only for float inputs like "42.0f")
		std::string tempLiteral = literal;
		if (tempLiteral[tempLiteral.length() - 1] == 'f')
			tempLiteral = tempLiteral.substr(0, tempLiteral.length() - 1); // Remove the 'f' at the end
		if (tempLiteral.empty()) {
			std::cerr << "Invalid input" << std::endl;
			return;
		}
		// Try converting the float without the 'f' at the end
		if (literal[literal.length() - 1] == 'f')
			value = static_cast<double>(std::strtof(tempLiteral.c_str(), &endPtr));  // Convert to float
		else
			value = std::strtod(tempLiteral.c_str(), &endPtr);  // Convert to double

		if (*endPtr != '\0') {
			std::cerr << "Invalid input" << std::endl;
			return;
		}
	}
	// Convert to char
	std::cout << "Char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	// Convert to int
	std::cout << "Int: ";
	if (std::isnan(value) || std::isinf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "impossible" << std::endl;
	else if (std::fabs(value - static_cast<int>(value)) > 1e-6)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
	// Convert to float
	std::cout << "Float: ";
	std::cout << static_cast<float>(value);
	if (std::isnan(value))
		std::cout << "f" << std::endl;
	else if (std::isinf(value)) {
		if (value > 0)
			std::cout << "f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	else {
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	// Convert to double
	std::cout << "Double: ";
	std::cout << value;
	if (!std::isnan(value) && !std::isinf(value) && value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}
