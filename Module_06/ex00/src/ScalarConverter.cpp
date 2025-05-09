/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:50:57 by olthorel          #+#    #+#             */
/*   Updated: 2025/05/09 16:38:53 by olthorel         ###   ########.fr       */
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
	//verif is char
	if (isChar(literal)) {
		c = literal[0];
		value = static_cast<double>(c);
	}
	//verif is pseudo literal
	else if (isPseudoLiteral(literal)) {
		if (literal.back() == 'f')
			value = static_cast<double>(std::strtof(literal.c_str(), NULL));
		else
			value = std::strtod(literal.c_str(), NULL);
	}
	//try to convert in double
	else {
		try {
			value = std::strtod(literal.c_str(), NULL);
		} catch (...) {
			std::cerr << "Invalid input" << std::endl;
			return ;
		}
	}
	//convert to char
	std::cout << "Char: ";
	if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "No displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	//convert to int
}